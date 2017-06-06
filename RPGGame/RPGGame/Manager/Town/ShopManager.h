#ifndef __SHOPMANAGER_H__
#define __SHOPMANAGER_H__

#include "Singleton.h"

#include "Shop.h"

class ShopManager :public Singleton<ShopManager>
{
public:
    ShopManager();
    ~ShopManager();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init();

public:
    const Shop &GetShop();

    /**
    * @brief ������Ʒ
    */
    bool BuyGoods(const int iIndex, const int iNum);

    /**
    * @brief ������Ʒ
    */
    bool SellGoods(const int iIndex, const int iNum);
private:
    /*!< ��Ʒ */
    Shop m_oShop;
};



#endif // __SHOPMANAGER_H__


