
#ifndef __FRAMECONFIG_LOADER_H__
#define __FRAMECONFIG_LOADER_H__


/*!< ѡ��������� */
#define MAX_OPTION_NUM 5


#define g_FrameConfigLoader FrameConfigLoader::GetInstance()

#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;



/**
 * @brief ѡ��
 */
struct Option
{
	/*!< ֪ͨ���� */
	int iNotify;

	/*!< ��Ӧ��ID */
	int iFrameID;

	/*!< ѡ������ */
	int iData;


	/*!< ѡ������ */
	string sDescription;

};

/**
 * @brief ������
 */
struct FrameConfig
{	
		/*!< ��� */
		int iID;
		
		/*!< ������ */
		int iX;
		
		/*!< ������ */
		int iY;
		
		/*!< ��� */
		int iWidth;
		
		/*!< �߶� */
		int iHeight;
		
		/*!< ��Ӧ���� */
		int iHandleID;
	
	
		/*!< ���� */
		string sName;
		
		/*!< ���� */
		string sDescription;
	


		/*!< ѡ�� */
		vector<Option> vecOption;

};

class FrameConfigLoader : public Singleton<FrameConfigLoader>
{
public:
	/**
	 * @brief ��ʼ��
	 */
    bool Init();
	
public:
	/**
	 * @brief ��ȡȫ������
	 */
	const vector<FrameConfig> &GetAllConfig();
	
	/**
	 * @brief ͨ��������ȡ����
	 */
	const FrameConfig *GetFrameConfigByIndex(const unsigned int uIndex);
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const FrameConfig *GetFrameConfigByID(const int iID);
		
	/**
	 * @brief ͨ���������ȡ����
	 */
	const FrameConfig *GetFrameConfigByX(const int iX);
		
	/**
	 * @brief ͨ���������ȡ����
	 */
	const FrameConfig *GetFrameConfigByY(const int iY);
		
	/**
	 * @brief ͨ����Ȼ�ȡ����
	 */
	const FrameConfig *GetFrameConfigByWidth(const int iWidth);
		
	/**
	 * @brief ͨ���߶Ȼ�ȡ����
	 */
	const FrameConfig *GetFrameConfigByHeight(const int iHeight);
		
	/**
	 * @brief ͨ����Ӧ�����ȡ����
	 */
	const FrameConfig *GetFrameConfigByHandleID(const int iHandleID);
	
	
	/**
	 * @brief ͨ�����ƻ�ȡ����
	 */
	const FrameConfig *GetFrameConfigByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const FrameConfig *GetFrameConfigByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<FrameConfig> m_vecRecords;
};

#endif //__FRAMECONFIG_LOADER_H__
