#ifndef __REQ_H__
#define __REQ_H__

#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;
using std::pair;

#include "Cmd.h"

/**
 * @brief 请求命名空间
 */
namespace req
{
    const static string i_Index = "i_Index";
    const static string i_Data = "i_Data";


    /**
    * @brief 请求类
    */
    class Req
    {
    public:
	    Req();
	    ~Req();
    public:
        /**
         * @brief 初始化
         */
        virtual bool Init(cmd::Command eCmd);

        /**
         * @brief 获取指令
         */
        cmd::Command GetCmd();

	    /**
	    * @brief 添加整型参数
	    */
	    void Add(string sKey, int iValue);

	    /**
	    * @brief 添加字符串参数
	    */
	    void Add(string sKey, string sValue);

	    /**
	    * @brief 添加数组参数
	    */
	    void Add(string sKey, vector<Req> vValue);

	    /**
	    * @brief 获取指定整型参数
	    */
	    const int GetInt(string sKey)const;

	    /**
	    * @brief 获取指定字符串参数
	    */
	    const string GetString(string sKey)const;

	    /**
	    * @brief 获取指定数组参数
	    */
	    const vector<Req> GetVector(string sKey)const;

	    /**
	    * @brief 是否有指定整型参数
	    */
	    const bool HasInt(string sKey)const;

	    /**
	    * @brief 是否有指定字符串参数
	    */
	    const bool HasString(string sKey)const;

	    /**
	    * @brief 是否有指定数组参数
	    */
	    const bool HasVector(string sKey)const;
    private:
	    /*!< 指令 */
        cmd::Command m_eCmd;
        /*!< 整型参数映射 */
	    map<string, int> m_mapIntArg;
	    /*!< 字符串参数映射 */
	    map<string, string> m_mapStringArg;
	    /*!< 数组参数映射 */
	    map<string, vector<Req>> m_mapVectorArg;

    };
};


#endif // __REQ_H__
