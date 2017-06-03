#include "Item.h"


Item::Item()
{
    m_oItemData.iID          = 0;
    m_oItemData.eType        = ITEM_TYPE_NO;
    m_oItemData.sName        = "��";
    m_oItemData.sDescription = "����Ʒ";
}


Item::~Item()
{
}

const Item & Item::GetNoItem()
{
    static Item oItem;
    return oItem;
}

bool Item::Init(const Item &oItem)
{
    m_oItemData = oItem.m_oItemData;
    return true;
}


bool Item::Init(const int iID, const ItemType eType, const string &sName, const string &sDestription)
{
    m_oItemData.iID          = iID;
    m_oItemData.eType        = eType;
    m_oItemData.sName        = sName;
    m_oItemData.sDescription = sDestription;
    return true;
}
