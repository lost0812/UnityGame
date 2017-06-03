
#ifndef __ITEMCONFIG_LOADER_H__
#define __ITEMCONFIG_LOADER_H__



#define g_ItemConfigLoader ItemConfigLoader::GetInstance()

#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;

/**
 * @brief ��Ʒ����
 */
enum ItemType
{
		/*!< ������ */
		ITEM_TYPE_NO = 0,

		/*!< ��ͨ���� */
		ITEM_TYPE_NORMAL = 1,

		/*!< �������� */
		ITEM_TYPE_EQUIPMENT = 2,

		/*!< �������ֵ */
		ITEM_TYPE_MAX = 3,

};

/**
 * @brief ��Ʒ����
 */
struct ItemConfig
{	
		/*!< ��� */
		int iID;
		
		/*!< ���� */
		ItemType eType;
	
	
		/*!< ���� */
		string sName;
		
		/*!< ���� */
		string sDescription;
	


};

class ItemConfigLoader : public Singleton<ItemConfigLoader>
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
	const vector<ItemConfig> &GetAllConfig();
	
	/**
	 * @brief ͨ��������ȡ����
	 */
	const ItemConfig *GetItemConfigByIndex(const unsigned int uIndex);
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const ItemConfig *GetItemConfigByID(const int iID);
		
	/**
	 * @brief ͨ�����ͻ�ȡ����
	 */
	const ItemConfig *GetItemConfigByType(const ItemType eType);
	
	
	/**
	 * @brief ͨ�����ֻ�ȡ����
	 */
	const ItemConfig *GetItemConfigByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const ItemConfig *GetItemConfigByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<ItemConfig> m_vecRecords;
};

#endif //__ITEMCONFIG_LOADER_H__
