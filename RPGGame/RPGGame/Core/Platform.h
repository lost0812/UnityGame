#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <windows.h>
#include <string>

using std::string;

/*!< ���ת���ַ������� */
#define MAX_STRING_LENGTH 1024

/**
* @brief ϵͳ��غ���
*/
namespace platform
{
	/**
	* @brief UTF-8����ת��ΪASCII����
	*/
	const std::string UTF_82ASCII(const std::string& sUtf8Code);

    /**
     * @brief ���������
     */
    int Rank(const int iMax);
};

#endif
