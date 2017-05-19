#ifndef __STRUTIL_H__
#define __STRUTIL_H__

#include <string>
#include <vector>
#include <map>
#include <stdarg.h>

using std::string;
using std::vector;
using std::map;

/**
 * @brief �ַ���������
 */
class StrUtil
{
private:
    StrUtil();
    ~StrUtil();
public:
    /**
     * @brief �ָ��ַ���
     */
    static int Split(const string &sBuffer, const string &sSeparate, vector<string> &vFragments);

    /**
     * @brief ��ʽ���ַ���
     */
    static string Format( const char *csFormat, ... );

    /**
     * @brief �ַ����滻
     */
    static int Replace(string &sSrc, const string sOld, const string sNew);

     /**
     * @brief �ַ����滻
     */
    static int Replace(string &sSrc, const map<string,string> &mapOld2New);

};


#endif // __STRUTIL_H__

