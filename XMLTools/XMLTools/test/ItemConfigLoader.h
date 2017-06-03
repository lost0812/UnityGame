
#ifndef __ITEMCONFIG_LOADER_H__
#define __ITEMCONFIG_LOADER_H__

#include <vector>

#include "Singleton.h"

using std::vector;

class ItemConfigLoader : public Singleton<ItemConfigLoader>
{
public:
	/**
	 * @brief ��Ʒ����
	 */
	struct ItemConfig
	{	
	/*!< ���� */
	ItemType eType;
		
	/*!< ���� */
	string sName;
		
	/*!< ���� */
	string sDescription;
	
	}

public:
	/**
	 * @brief ��ʼ��
	 */
    bool Init();
	
public:
	
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
    vector<ItemConfig> m_vecRecords;
}


#endif //__ITEMCONFIG_LOADER_H__
