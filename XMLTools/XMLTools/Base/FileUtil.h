#ifndef __FILEUTIL_H__
#define __FILEUTIL_H__

#include <string>

using std::string;

/**
 * @brief �ļ�������
 */
class FileUtil
{
private:
    FileUtil();
    ~FileUtil();

public:
    /**
     * @brief �����Ƹ�ʽ��ȡ�ļ�
     */
    static int LoadFileWithBinary(const string sFile, char *const csBuffer, const int iSize );

    /**
     * @brief �����Ƹ�ʽ�����ļ�
     */
    static int SaveFileWithBinary(const string sFile, const char *const csBuffer, const int iLength);

    /**
    * @brief �ַ���ʽ��ȡ�ļ�
    */
    static int LoadFileWithChar(const string sFile, char *const csBuffer, const int iSize);

    /**
    * @brief �ַ���ʽ�����ļ�
    */
    static int SaveFileWithChar(const string sFile, const char *const csBuffer, const int iLength);
};

#endif // __FILEUTIL_H__


