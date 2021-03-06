#! /usr/bin/env python
#coding=utf-8

##
# @file:   xls_deploy_tool.py
# @author: jameyli <lgy AT live DOT com>
# @brief:  xls 配置导表工具

# 主要功能：
#     1 配置定义生成，根据excel 自动生成配置的PB定义
#     2 配置数据导入，将配置数据生成PB的序列化后的二进制数据或者文本数据
#
# 说明:
#   1 excel 的前四行用于结构定义, 其余则为数据，按第一行区分, 分别解释：
#       required 必有属性
#       optional 可选属性
#           第二行: 属性类型
#           第三行：属性名
#           第四行：注释
#           数据行：属性值
#       repeated 表明下一个属性是repeated,即数组
#           第二行: repeat的最大次数, excel中会重复列出该属性
#           2011-11-29 做了修改 第二行如果是类型定义的话，则表明该列是repeated
#           但是目前只支持整形
#           第三行：无用
#           第四行：注释
#           数据行：实际的重复次数
#       required_struct 必选结构属性
#       optional_struct 可选结构属性
#           第二行：结构元素个数
#           第三行：结构名
#           第四行：在上层结构中的属性名
#           数据行：不用填

#    1  | required/optional | repeated  | required_struct/optional_struct   |
#       | ------------------| ---------:| ---------------------------------:|
#    2  | 属性类型          |           | 结构元素个数                      |
#    3  | 属性名            |           | 结构类型名                        |
#    4  | 注释说明          |           | 在上层结构中的属性名              |
#    5  | 属性值            |           |                                   |

#
#
# 开始设计的很理想，希望配置定义和配置数据保持一致,使用同一个excel
# 不知道能否实现
#
# 功能基本实现，并验证过可以通过CPP解析 ohye
#
# 2011-06-17 修改:
#   表名sheet_name 使用大写
#   结构定义使用大写加下划线
# 2011-06-20 修改bug:
#   excel命名中存在空格
#   repeated_num = 0 时的情况
# 2011-11-24 添加功能
#   默认值
# 2011-11-29 添加功能
# repeated 第二行如果是类型定义的话，则表明该列是repeated
# 但是目前只支持整形

# TODO::
# 1 时间配置人性化
# 2 区分server/client 配置
# 3 repeated 优化
# 4 struct 优化

# 依赖:
# 1 protobuf
# 2 xlrd
##


import xlrd # for read excel
import sys
import os
import wx
import re

# TAP的空格数
TAP_BLANK_NUM = 4

FILED_CS_BELONG_ROW = 0
FIELD_RULE_ROW = 1
# 这一行还表示重复的最大个数，或结构体元素数
FIELD_TYPE_ROW = 2
FIELD_NAME_ROW = 3
FIELD_COMMENT_ROW = 4

OUTPUT_FULE_PATH_BASE="dataconfig_"

########################################LogHelp###########################################

gWXApp = wx.App()
#小数匹配器
gDecimalPartner = re.compile("^\d+\.\d+$")

def PrintErrorInfo(strReason, strDetail):
    wx.MessageBox(strDetail, strReason)
    sys.exit(-1)

class LogHelp :
    """日志辅助类"""
    _logger = None
    _close_imme = True

    @staticmethod
    def set_close_flag(flag):
        LogHelp._close_imme = flag

    @staticmethod
    def _initlog():
        import logging

        LogHelp._logger = logging.getLogger()
        logfile = 'xls_deploy_tool.log'
        hdlr = logging.FileHandler(logfile)
        formatter = logging.Formatter('%(asctime)s|%(levelname)s|%(lineno)d|%(funcName)s|%(message)s')
        hdlr.setFormatter(formatter)
        LogHelp._logger.addHandler(hdlr)
        LogHelp._logger.setLevel(logging.NOTSET)
        # LogHelp._logger.setLevel(logging.WARNING)

        LogHelp._logger.info("\n\n\n")
        LogHelp._logger.info("logger is inited!")

    @staticmethod
    def get_logger() :
        if LogHelp._logger is None :
            LogHelp._initlog()

        return LogHelp._logger

    @staticmethod
    def close() :
        if LogHelp._close_imme:
            import logging
            if LogHelp._logger is None :
                return
            logging.shutdown()

# log macro
LOG_DEBUG=LogHelp.get_logger().debug
LOG_INFO=LogHelp.get_logger().info
LOG_WARN=LogHelp.get_logger().warn
LOG_ERROR=LogHelp.get_logger().error


########################################SheetInterpreter###########################################
class SheetInterpreter:
    """通过excel配置生成配置的protobuf定义文件"""
    def __init__(self, xls_file_path, sheet_name, op2):
        self._xls_file_path = xls_file_path
        self._sheet_name = sheet_name
        self._cs_belong = op2.lower()

        try :
            self._workbook = xlrd.open_workbook(self._xls_file_path)
        except BaseException, e :
            PrintErrorInfo("Open Xls File Failed", self._xls_file_path)
            print "open xls file(%s) failed!"%(self._xls_file_path)
            raise

        try :
            self._sheet =self._workbook.sheet_by_name(self._sheet_name)
        except BaseException, e :
            PrintErrorInfo("Open Sheet Failed", self._sheet_name)
            print "open sheet(%s) failed!"%(self._sheet_name)

        # 行数和列数
        self._row_count = len(self._sheet.col_values(0))
        self._col_count = len(self._sheet.row_values(0))

        self._row = 0
        self._col = 0

        # 将所有的输出先写到一个list， 最后统一写到文件
        self._output = []
        # 排版缩进空格数
        self._indentation = 0
        # field number 结构嵌套时使用列表
        # 新增一个结构，行增一个元素，结构定义完成后弹出
        self._field_index_list = [1]
        # 当前行是否输出，避免相同结构重复定义
        self._is_layout = True
        # 保存所有结构的名字
        self._struct_name_list = []

        self._pb_file_name = OUTPUT_FULE_PATH_BASE + sheet_name.lower() + ".proto"


    def Interpreter(self) :
        """对外的接口"""
        LOG_INFO("begin Interpreter, row_count = %d, col_count = %d", self._row_count, self._col_count)

        #proto的文件头
        self._LayoutFileHeader()

        #proto的包名
        self._output.append("package dataconfig;\n")

        #结构头
        self._LayoutStructHead(self._sheet_name)

        #增加缩进
        self._IncreaseIndentation()

        while self._col < self._col_count :
            self._FieldDefine(0)

        #减少缩进
        self._DecreaseIndentation()

        #生成结构尾
        self._LayoutStructTail()

        #输出数组定义
        self._LayoutArray()

        #输出到文件
        self._Write2File()

        LogHelp.close()

        # 将PB转换成py格式
        try :
            command = "protoc --python_out=. " + self._pb_file_name
            os.system(command)
        except BaseException, e :
            PrintErrorInfo("Protoc Failed", e)
            print "protoc failed!"
            raise

    #每个字段的定义
    def _FieldDefine(self, repeated_num) :
        LOG_INFO("row=%d, col=%d, repeated_num=%d", self._row, self._col, repeated_num)

        belong_rule = str(self._sheet.cell_value(FILED_CS_BELONG_ROW, self._col)).lower()
        field_rule = str(self._sheet.cell_value(FIELD_RULE_ROW, self._col))

        if belong_rule != self._cs_belong and belong_rule != "cs" and belong_rule != "":
            self._col += 1
            return

        if field_rule == "required" or field_rule == "optional" :
            field_type = str(self._sheet.cell_value(FIELD_TYPE_ROW, self._col)).strip()
            field_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
            field_comment = unicode(self._sheet.cell_value(FIELD_COMMENT_ROW, self._col))


            LOG_INFO("%s|%s|%s|%s", field_rule, field_type, field_name, field_comment)

            comment = field_comment.encode("utf-8")
            self._LayoutComment(comment)

            if repeated_num >= 1:
                field_rule = "repeated"

            self._LayoutOneField(field_rule, field_type, field_name)

            actual_repeated_num = 1 if (repeated_num == 0) else repeated_num
            self._col += actual_repeated_num

        elif field_rule == "repeated" :
            # 2011-11-29 修改
            # 若repeated第二行是类型定义，则表示当前字段是repeated，并且数据在单列用分好相隔
            second_row = str(self._sheet.cell_value(FIELD_TYPE_ROW, self._col)).strip()
            LOG_DEBUG("repeated|%s", second_row);
            # exel有可能有小数点
            if second_row.isdigit() or second_row.find(".") != -1 :
                # 这里后面一般会是一个结构体
                repeated_num = int(float(second_row))
                LOG_INFO("%s|%d", field_rule, repeated_num)
                self._col += 1
                self._FieldDefine(repeated_num)
            else :
                # 一般是简单的单字段，数值用分号相隔
                field_type = second_row
                field_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
                field_comment = unicode(self._sheet.cell_value(FIELD_COMMENT_ROW, self._col))
                LOG_INFO("%s|%s|%s|%s", field_rule, field_type, field_name, field_comment)

                comment = field_comment.encode("utf-8")
                self._LayoutComment(comment)

                self._LayoutOneField(field_rule, field_type, field_name)

                self._col += 1

        elif field_rule == "required_struct" or field_rule == "optional_struct":
            field_num = int(self._sheet.cell_value(FIELD_TYPE_ROW, self._col))
            # struct_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
            # field_name = str(self._sheet.cell_value(FIELD_COMMENT_ROW, self._col)).strip()
            field_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
            struct_name = "InternalType_" + field_name;
            field_comment = unicode(self._sheet.cell_value(FIELD_COMMENT_ROW, self._col))
            comment = field_comment.encode("utf-8")

            LOG_INFO("%s|%d|%s|%s", field_rule, field_num, struct_name, field_name)


            if (self._IsStructDefined(struct_name)) :
                self._is_layout = False
            else :
                self._struct_name_list.append(struct_name)
                self._is_layout = True

            self._col += 1
            col_begin = self._col
            self._StructDefine(struct_name, field_num, comment)
            col_end = self._col

            self._is_layout = True

            if repeated_num >= 1:
                field_rule = "repeated"
            elif field_rule == "required_struct":
                field_rule = "required"
            else:
                field_rule = "optional"

            self._LayoutOneField(field_rule, struct_name, field_name)

            actual_repeated_num = 1 if (repeated_num == 0) else repeated_num
            self._col += (actual_repeated_num-1) * (col_end-col_begin)
        else :
            self._col += 1
            return

    def _IsStructDefined(self, struct_name) :
        for name in self._struct_name_list :
            if name == struct_name :
                return True
        return False

    def _StructDefine(self, struct_name, field_num, comment) :
        """嵌套结构定义"""

        # self._col += 1
        self._LayoutComment(comment)
        self._LayoutStructHead(struct_name)
        self._IncreaseIndentation()
        self._field_index_list.append(1)

        while field_num > 0 :
            self._FieldDefine(0)
            field_num -= 1

        self._field_index_list.pop()
        self._DecreaseIndentation()
        self._LayoutStructTail()

    def _LayoutFileHeader(self) :
        """生成PB文件的描述信息"""
        self._output.append("/**\n")
        self._output.append("* @file:   " + self._pb_file_name + "\n")
        self._output.append("* @brief:  这个文件是通过工具自动生成的，建议不要手动修改\n")
        self._output.append("*/\n")
        self._output.append("\n")


    def _LayoutStructHead(self, struct_name) :
        """生成结构头"""
        if not self._is_layout :
            return
        self._output.append("\n")
        self._output.append(" "*self._indentation + "message " + struct_name + "{\n")

    def _LayoutStructTail(self) :
        """生成结构尾"""
        if not self._is_layout :
            return
        self._output.append(" "*self._indentation + "}\n")
        self._output.append("\n")

    def _LayoutComment(self, comment) :
        # 改用C风格的注释，防止会有分行
        if not self._is_layout :
            return
        if comment.count("\n") > 1 :
            if comment[-1] != '\n':
                comment = comment + "\n"
                comment = comment.replace("\n", "\n" + " " * (self._indentation + TAP_BLANK_NUM),
                        comment.count("\n")-1 )
                self._output.append(" "*self._indentation + "/** " + comment + " "*self._indentation + "*/\n")
        else :
            self._output.append(" "*self._indentation + "/** " + comment + " */\n")

    def _LayoutOneField(self, field_rule, field_type, field_name) :
        """输出一行定义"""
        if not self._is_layout :
            return
        if field_name.find('=') > 0 :
            name_and_value = field_name.split('=')
            self._output.append(" "*self._indentation + field_rule + " " + field_type \
                    + " " + str(name_and_value[0]).strip() + " = " + self._GetAndAddFieldIndex()\
                    + " [default = " + str(name_and_value[1]).strip() + "]" + ";\n")
            return
        
        if (field_rule != "required" and field_rule != "optional") :
            self._output.append(" "*self._indentation + field_rule + " " + field_type \
                    + " " + field_name + " = " + self._GetAndAddFieldIndex() + ";\n")
            return
        
        if field_type == "int32" or field_type == "int64"\
                or field_type == "uint32" or field_type == "uint64"\
                or field_type == "sint32" or field_type == "sint64"\
                or field_type == "fixed32" or field_type == "fixed64"\
                or field_type == "sfixed32" or field_type == "sfixed64" \
                or field_type == "double" or field_type == "float" :
                    self._output.append(" "*self._indentation + field_rule + " " + field_type \
                            + " " + field_name + " = " + self._GetAndAddFieldIndex()\
                            + " [default = 0]" + ";\n")
        elif field_type == "string" or field_type == "bytes" :
            self._output.append(" "*self._indentation + field_rule + " " + field_type \
                    + " " + field_name + " = " + self._GetAndAddFieldIndex()\
                    + " [default = \"\"]" + ";\n")
        elif field_type == "DateTime" :
            field_type = "uint64"
            self._output.append(" "*self._indentation + field_rule + " " + field_type \
                    + " /*DateTime*/ " + field_name + " = " + self._GetAndAddFieldIndex()\
                    + " [default = 0]" + ";\n")
        elif field_type == "TimeDuration" :
            field_type = "uint64"
            self._output.append(" "*self._indentation + field_rule + " " + field_type \
                    + " /*TimeDuration*/ " + field_name + " = " + self._GetAndAddFieldIndex()\
                    + " [default = 0]" + ";\n")
        else :
            self._output.append(" "*self._indentation + field_rule + " " + field_type \
                    + " " + field_name + " = " + self._GetAndAddFieldIndex() + ";\n")
        return

    def _IncreaseIndentation(self) :
        """增加缩进"""
        self._indentation += TAP_BLANK_NUM

    def _DecreaseIndentation(self) :
        """减少缩进"""
        self._indentation -= TAP_BLANK_NUM

    def _GetAndAddFieldIndex(self) :
        """获得字段的序号, 并将序号增加"""
        index = str(self._field_index_list[- 1])
        self._field_index_list[-1] += 1
        return index

    def _LayoutArray(self) :
        """输出数组定义"""
        self._output.append("message " + self._sheet_name + "Array {\n")
        self._output.append("    repeated " + self._sheet_name + " items = 1;\n}\n")

    def _Write2File(self) :
        """输出到文件"""
        pb_file = open(self._pb_file_name, "w+")
        pb_file.writelines(self._output)
        pb_file.close()


########################################DataParser###########################################
class DataParser:
    """解析excel的数据"""
    def __init__(self, xls_file_path, sheet_name, op2):
        self._xls_file_path = xls_file_path
        self._sheet_name = sheet_name
        self._cs_belong = op2

        try :
            self._workbook = xlrd.open_workbook(self._xls_file_path)
        except BaseException, e :
            PrintErrorInfo("Open Xls File", self._xls_file_path)
            print "open xls file(%s) failed!"%(self._xls_file_path)
            raise

        try :
            self._sheet =self._workbook.sheet_by_name(self._sheet_name)
        except BaseException, e :
            PrintErrorInfo("Open Sheet Failed", self._sheet_name)
            print "open sheet(%s) failed!"%(self._sheet_name)
            raise

        self._row_count = len(self._sheet.col_values(0))
        self._col_count = len(self._sheet.row_values(0))

        self._row = 0
        self._col = 0

        try:
            self._module_name = OUTPUT_FULE_PATH_BASE + self._sheet_name.lower() + "_pb2"
            sys.path.append(os.getcwd())
            exec('from '+self._module_name + ' import *');
            self._module = sys.modules[self._module_name]
        except BaseException, e :
            PrintErrorInfo("Load Module Failed", self._module_name)
            print "load module(%s) failed"%(self._module_name)
            raise

    def Parse(self) :
        """对外的接口:解析数据"""
        LOG_INFO("begin parse, row_count = %d, col_count = %d", self._row_count, self._col_count)

        item_array = getattr(self._module, self._sheet_name+'Array')()

        # 先找到定义ID的列
        id_col = 0
        for id_col in range(0, self._col_count) :
            info_id = str(self._sheet.cell_value(self._row, id_col)).strip()
            if info_id == "" :
                continue
            else :
                break
        
        
        #由于增加了一行CS_BELONG,所以要从第6（索引为5）行开始了
        for self._row in range(5, self._row_count) :
            # 如果 id 是 空 直接跳过改行
            info_id = str(self._sheet.cell_value(self._row, id_col)).strip()
            if info_id == "" :
                LOG_WARN("%d is None", self._row)
                continue
            item = item_array.items.add()
            self._ParseLine(item)

        LOG_INFO("parse result:\n%s", item_array)

        self._WriteReadableData2File(str(item_array))

        data = item_array.SerializeToString()
        self._WriteData2File(data)


        #comment this line for test .by kevin at 2013年1月12日 17:23:35
        LogHelp.close()

    def _ParseLine(self, item) :
        LOG_INFO("%d", self._row)

        self._col = 0
        while self._col < self._col_count :
            self._ParseField(0, 0, item)

    def _ParseField(self, max_repeated_num, repeated_num, item) :
        # 解析跳过逻辑
        belong_rule = str(self._sheet.cell_value(FILED_CS_BELONG_ROW, self._col)).lower()
        if belong_rule != self._cs_belong and belong_rule != "cs" and belong_rule != "":
            self._col += 1
            return

        field_rule = str(self._sheet.cell_value(FIELD_RULE_ROW, self._col)).strip()


        if field_rule == "required" or field_rule == "optional" :
            field_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
            if field_name.find('=') > 0 :
                name_and_value = field_name.split('=')
                field_name = str(name_and_value[0]).strip()
            field_type = str(self._sheet.cell_value(FIELD_TYPE_ROW, self._col)).strip()

            LOG_INFO("%d|%d", self._row, self._col)
            LOG_INFO("%s|%s|%s", field_rule, field_type, field_name)

            if max_repeated_num == 0 :
                field_value = self._GetFieldValue(field_type, self._row, self._col)
                
                #增加必须字段非空的检测 add by lynn
                #if  field_rule == "required" and field_value == None:
                #   self._PrintBadField("Requried Field, But Value Is Empty")

                # 有value才设值
                if field_value != None :
                    item.__setattr__(field_name, field_value)
                self._col += 1
            else :
                if repeated_num == 0 :
                    if field_rule == "required" :
                        self._PrintBadField("required but repeated_num = 0")
                        print "required but repeated_num = 0"
                        raise
                else :
                    for col in range(self._col, self._col + repeated_num):
                        field_value = self._GetFieldValue(field_type, self._row, col)

                        #增加必须字段非空的检测 add by lynn
                        #if field_rule == "required" and field_value == None:
                        #   self._PrintBadField("Requried Field, But Value Is Empty")

                        # 有value才设值
                        if field_value != None :
                            item.__getattribute__(field_name).append(field_value)
                self._col += max_repeated_num

        elif field_rule == "repeated" :
            # 2011-11-29 修改
            # 若repeated第二行是类型定义，则表示当前字段是repeated，并且数据在单列用分好相隔
            second_row = str(self._sheet.cell_value(FIELD_TYPE_ROW, self._col)).strip()
            LOG_DEBUG("repeated|%s", second_row);
            # exel有可能有小数点
            if second_row.isdigit() or second_row.find(".") != -1 :
                # 这里后面一般会是一个结构体
                max_repeated_num = int(float(second_row))
                read = self._sheet.cell_value(self._row, self._col)
                repeated_num = 0 if read == "" else int(self._sheet.cell_value(self._row, self._col))

                LOG_INFO("%s|%d|%d", field_rule, max_repeated_num, repeated_num)

                if max_repeated_num == 0 :
                    self._PrintBadField("max repeated num shouldn't be 0")
                    print "max repeated num shouldn't be 0"
                    raise

                if repeated_num > max_repeated_num :
                    repeated_num = max_repeated_num

                self._col += 1
                self._ParseField(max_repeated_num, repeated_num, item)

            else :
                # 一般是简单的单字段，数值用分号相隔
                # 一般也只能是数字类型
                field_type = second_row
                field_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
                field_value_str = unicode(self._sheet.cell_value(self._row, self._col))
                #field_value_str = unicode(self._sheet.cell_value(self._row, self._col)).strip()

                # LOG_INFO("%d|%d|%s|%s|%s",
                #         self._row, self._col, field_rule, field_type, field_name, field_value_str)

                #2013-01-24 jamey
                #增加长度判断
                if len(field_value_str) > 0:
                    if field_value_str.find(";\n") > 0 :
                        field_value_list = field_value_str.split(";\n")
                    else :
                        field_value_list = field_value_str.split(";")

                    for field_value in field_value_list :
                        #多余的分号容错处理 add by lynn
                        if field_value == "":
                            continue

                        if field_type == "bytes" or field_type == "string" :
                            item.__getattribute__(field_name).append(field_value.encode("utf8"))
                        else:
                            #负数检查 add by lynn
                            data_value = int(float(field_value))
                            if field_type == "uint32" or field_type == "uint64":
                                if data_value < 0:
                                    self._PrintBadField("Unsigned Num Is Less 0")
                            item.__getattribute__(field_name).append(int(float(field_value)))

                self._col += 1

        elif field_rule == "required_struct" or field_rule == "optional_struct":
            field_num = int(self._sheet.cell_value(FIELD_TYPE_ROW, self._col))
            # struct_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
            # field_name = str(self._sheet.cell_value(FIELD_COMMENT_ROW, self._col)).strip()
            field_name = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
            struct_name = "InternalType_" + field_name;

            LOG_INFO("%s|%d|%s|%s", field_rule, field_num, struct_name, field_name)


            self._col += 1
            col_begin = self._col

            # 至少循环一次
            if max_repeated_num == 0 :
                struct_item = item.__getattribute__(field_name)
                self._ParseStruct(field_num, struct_item)

            else :
                if repeated_num == 0 :
                    if field_rule == "required_struct" :
                        self._PrintBadField("required but repeated_num = 0")
                        print "required but repeated_num = 0"
                        raise
                    # 先读取再删除掉
                    struct_item = item.__getattribute__(field_name).add()
                    self._ParseStruct(field_num, struct_item)
                    item.__getattribute__(field_name).__delitem__(-1)

                else :
                    for num in range(0, repeated_num):
                        struct_item = item.__getattribute__(field_name).add()
                        self._ParseStruct(field_num, struct_item)

            col_end = self._col

            max_repeated_num = 1 if (max_repeated_num == 0) else max_repeated_num
            actual_repeated_num = 1 if (repeated_num==0) else repeated_num
            self._col += (max_repeated_num - actual_repeated_num) * ((col_end-col_begin)/actual_repeated_num)

        else :
            self._col += 1
            return

    def _ParseStruct(self, field_num, struct_item) :
        """嵌套结构数据读取"""

        # 跳过结构体定义
        # self._col += 1
        while field_num > 0 :
            self._ParseField(0, 0, struct_item)
            field_num -= 1

    def _GetFieldValue(self, field_type, row, col) :
        """将pb类型转换为python类型"""

        field_value = self._sheet.cell_value(row, col)
        LOG_INFO("%d|%d|%s", row, col, field_value)
        
        try:
            if field_type == "int32" or field_type == "int64"\
                    or  field_type == "uint32" or field_type == "uint64"\
                    or field_type == "sint32" or field_type == "sint64"\
                    or field_type == "fixed32" or field_type == "fixed64"\
                    or field_type == "sfixed32" or field_type == "sfixed64" :
                        if len(str(field_value).strip()) <=0 :
                            return None
                        else :
                            #增加无符号的类型，填成了负数的检测 lynn
                            data = int(field_value)
                            if field_type == "uint32" or field_type == "uint64":
                                if data < 0:
                                    self._PrintBadField("Unsigned Num Is Less 0")
                            return int(field_value)
            elif field_type == "double" or field_type == "float" :
                    if len(str(field_value).strip()) <=0 :
                        return None
                    else :
                        return float(field_value)
            elif field_type == "string" :
                field_value = unicode(field_value)
                if len(field_value) <= 0 :
                    return None
                else :
                    #增加string不是文本格式的检查 add by lynn,string类型如果不是文本格式，数字后面会加.00，时间格式会被转化小数
                    if gDecimalPartner.match(field_value) != None:
                       self._PrintBadField("string bad format, please using 'txt format' ")
                    return field_value
            elif field_type == "bytes" :
                field_value = unicode(field_value).encode('utf-8')
                if len(field_value) <= 0 :
                    return None
                else :
                    return field_value
            elif field_type == "DateTime" :
                field_value = unicode(field_value).encode('utf-8')
                if len(field_value) <= 0 :
                    return 0
                else :
                    import time
                    time_struct = time.strptime(field_value, "%Y-%m-%d %H:%M:%S")
                    timt_stamp = int(time.mktime(time_struct))
                    return timt_stamp
            elif field_type == "TimeDuration" :
                field_value = unicode(field_value).encode('utf-8')
                if len(field_value) <= 0 :
                    return 0
                else :
                    import datetime
                    import time
                    time_struct=0
                    try :
                        time_struct = time.strptime(field_value, "%HH")
                    except BaseException, e :
                        time_struct = time.strptime(field_value, "%jD%HH")
                    return 3600 * (time_struct.tm_yday * 24 + time_struct.tm_hour)
            elif field_type == "bool":
                return bool(field_value)
            else :
                self._PrintBadField("Not Support Type")
                return None
        except BaseException, e :
            self._PrintBadField("Bad Data Format!")
            print "parse cell(%u, %u) error, please check it, maybe type is wrong."%(row, col)
            raise

    def _WriteData2File(self, data) :
        file_name = OUTPUT_FULE_PATH_BASE + self._sheet_name.lower() + ".data"
        file = open(file_name, 'wb+')
        file.write(data)
        file.close()

    def _WriteReadableData2File(self, data) :
        file_name = OUTPUT_FULE_PATH_BASE + self._sheet_name.lower() + ".txt"
        file = open(file_name, 'wb+')
        file.write(data)
        file.close()

    def _PrintBadField(self, strReason):
        strFieldName = str(self._sheet.cell_value(FIELD_NAME_ROW, self._col)).strip()
        strFieldInfo = "File: " + self._xls_file_path + "\nSheet: " +\
                        self._sheet_name + "\nFiledName: " + strFieldName +\
                        "\nCol: " + str(self._col + 1) + "\nRow: " + str(self._row + 1)
        wx.MessageBox(strFieldInfo, strReason)
        sys.exit(-1)



########################################__main__###########################################
if __name__ == '__main__' :
    """入口"""
    if len(sys.argv) < 3 :
        print "Usage: %s sheet_name(should be upper) xls_file" %(sys.argv[0])
        sys.exit(-1)

    # option 0 生成proto和data 1 只生成proto 2 只生成data
    op = 0
    belong_op = "c"

    if len(sys.argv) > 3 :
        belong_op= str(sys.argv[3])

    if len(sys.argv) > 4 :
        op = int(sys.argv[4])

    sheet_name =  sys.argv[1]

    '''
    if (not sheet_name.isupper()):
        print "sheet_name should be upper"
        sys.exit(-2)
    '''

    xls_file_path =  sys.argv[2]

    if op == 0 or op == 1:
        try :
            tool = SheetInterpreter(xls_file_path, sheet_name, belong_op)
            tool.Interpreter()
        except BaseException, e :
            print "Interpreter Failed!!!"
            print e
            sys.exit(-3)

        print "Interpreter Success!!!"

    if op == 0 or op == 2:
        try :
            parser = DataParser(xls_file_path, sheet_name, belong_op)
            parser.Parse()
        except BaseException, e :
            print "Parse Failed!!!"
            print e
            sys.exit(-4)

        print "Parse Success!!!"

