
#ifndef __ITEM_LOADER_H__
#define __ITEM_LOADER_H__



#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;

class ItemLoader : public Singleton<ItemLoader>
{
public:
	/**
	 * @brief ��Ʒ����
	 */
	enum ItemType
	{
		/*!< ������ */
		ITEM_TYPE_NO = 0;

		/*!< ��ͨ���� */
		ITEM_TYPE_NORMAL = 1;

		/*!< �������� */
		ITEM_TYPE_EQUIPMENT = 2;

		/*!< �������ֵ */
		ITEM_TYPE_MAX = 3;

	}


	/**
	 * @brief ��Ʒ����
	 */
	struct Item
	{	
		/*!< ��� */
		int iID;
		
		/*!< ���� */
		Item::ItemType eType;
	
		
		/*!< ���� */
		string sName;
		
		/*!< ���� */
		string sDescription;
	
	
	
	};

public:
	/**
	 * @brief ��ʼ��
	 */
    bool Init();
	
public:
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const Item *GetItemByID(const int iID);
		
	/**
	 * @brief ͨ�����ͻ�ȡ����
	 */
	const Item *GetItemByType(const Item::ItemType eType);
	
	
	/**
	 * @brief ͨ�����ֻ�ȡ����
	 */
	const Item *GetItemByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const Item *GetItemByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<Item> m_vecRecords;
}


#endif //__ITEM_LOADER_H__
