#ifndef __ITEM_H__
#define __ITEM_H__

#include "Struct.h"
#include <string>

using std::string;
/**
 * @brief ��Ʒ��
 */
class Item
{
public:
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
        ITEM_TYPE_MAX = 3
    };
public:
	Item();
	~Item();
public:
    /**
     * @brief ����Ʒ
     */
    static const Item &GetNoItem();
public:
	/**
	 * @brief ��ʼ��
	 */
	virtual bool Init(const Item &oItem);

    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const int iID, const Item::ItemType eType, const string &sName, const string &sDestription);
public:
    SET_GET(int, i, ID, m_oItemData.iID);
    SET_GET(Item::ItemType, e, Type, m_oItemData.eType);
    SET_GET(string, s, Name, m_oItemData.sName);
    SET_GET(string, s, Description, m_oItemData.sDescription);
private:
    /**
    * @brief ��Ʒ����
    */
    struct ItemData
    {
        /*<! ��� */
        int iID;

        /*<! ���� */
        ItemType eType;

        /*<! ���� */
        string sName;

        /*<! ���� */
        string sDescription;
    };
private:
	/*!< ��Ʒ���� */
	ItemData m_oItemData;
};


#endif // __ITEM_H__

