#ifndef __LOG__H__
#define __LOG__H__

#include <cstdarg>
#include <string>
#include "Singleton.h"

#define MLog( type, format, ... ) Write(type,#type,__LINE__,__FUNCTION__, format, ##__VA_ARGS__ )
#define GLog( type, format, ... ) Log::GetInstance().Write(type,#type,__LINE__,__FUNCTION__, format, ##__VA_ARGS__ )

using std::string;

/**
 * @brief ��־��
 */
class Log:public Singleton<Log>
{
public:
    /**
     * @brief ��־�ȼ�����
     */
    enum LogType
    {
        /*!< ���� */
        LOG_ERROR = 1,

        /*!< ���� */
        LOG_WARMING = 2,

        /*!< ��Ϣ */
        LOG_INFO = 3,

        /*!< ���� */
        LOG_DEBUG   = 4
    };
public:
    Log();
	Log(const string sFile, const Log::LogType eType);
	~Log(void);
public:
    /**
     * @brief ��־��ʼ��
     */
    bool Init(const string sFile, const Log::LogType eType);

    /**
     * @brief ��־���
     */
	void Write( 
        const Log::LogType eType,
        const char *sType, 
        const int iLine, 
        const char *pFunction, 
        const char *pFormat,
        ... );

private:
    /**
     * @brief ��ȡ��ǰ��ʽ��ʱ��
     */
    void GetNowTime(char *const csTime);

private:
    /*!< ��־�ȼ����� */
    Log::LogType m_eType;

    /*!< ��־�ļ� */
    string m_sFile;
};


#endif

