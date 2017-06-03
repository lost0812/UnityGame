#ifndef __ITEMMANAGER_H__
#define __ITEMMANAGER_H__

#include <string>

#include "Singleton.h"
#include "ItemConfigLoader.h"

using std::string;
/**
* @brief ��Ʒ����
*/
class ItemManager :public Singleton<ItemManager>
{
public:
	ItemManager();
	~ItemManager();
public:
	/**
	 * @brief ��ʼ��
	 */
	virtual bool Init();
public:
    /**
     * @brief ��ȡ��Ʒ����
     */
    const ItemType GetTypeByID(const int iID)const;

    /**
     * @brief ��ȡ��Ʒ����
     */
    const string GetNameByID(const int iID)const;

    /**
     * @brief ��ȡ��Ʒ����
     */
    const string GetDescriptionByID(const int iID)const;

    /**
     * @brief ��ȡ��Ʒ����
     */
    const ItemConfig *GetItemByID(const int iID)const;

};

#endif