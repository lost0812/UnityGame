
#ifndef __DROPCONFIG_LOADER_H__
#define __DROPCONFIG_LOADER_H__



#define g_DropConfigLoader DropConfigLoader::GetInstance()

#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;



/**
 * @brief ����
 */
struct DropConfig
{	
		/*!< ��� */
		int iID;
		
		/*!< ��Ʒ��� */
		int iItemID;
		
		/*!< ��Ʒ���� */
		int iItemNum;
	



};

class DropConfigLoader : public Singleton<DropConfigLoader>
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
	const vector<DropConfig> &GetAllConfig();
	
	/**
	 * @brief ͨ��������ȡ����
	 */
	const DropConfig *GetDropConfigByIndex(const unsigned int uIndex);
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const DropConfig *GetDropConfigByID(const int iID);
		
	/**
	 * @brief ͨ����Ʒ��Ż�ȡ����
	 */
	const DropConfig *GetDropConfigByItemID(const int iItemID);
		
	/**
	 * @brief ͨ����Ʒ������ȡ����
	 */
	const DropConfig *GetDropConfigByItemNum(const int iItemNum);
	

private:
	/*!< �������� */
    vector<DropConfig> m_vecRecords;
};

#endif //__DROPCONFIG_LOADER_H__
