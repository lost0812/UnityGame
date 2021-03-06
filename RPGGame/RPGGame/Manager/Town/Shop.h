#ifndef __SHOP_H__
#define __SHOP_H__

#include <vector>

#include "Goods.h"
#include "ShopConfigLoader.h"

using std::vector;

class Shop
{
public:
    /**
    * @brief 商店类型
    */
    enum ShopType
    {
        SHOP_TYPE_NORMAL,
        SHOP_TYPE_MAX,
    };
public:
    Shop();
    ~Shop();

public:
    /**
    * @brief 初始化
    */
    virtual bool Init();

public:
    /**
    * @brief 获取全部商品信息
    */
    const vector<ShopConfig> &GetAllGoods()const;

    /**
    * @brief 购买商品
    */
    bool BuyGoods(const int iGoodsID, const int iNum, int &iPrice, int &iCapacity);

    /**
    * @brief 出售商品
    */
    bool SellGoods(const int iIndex, const int iNum);

public:
    /**
    * @brief 获取商品类别数量
    */
    int GetGoodsNum()const;

    /**
    * @brief 获取商品的物品编号
    */
    int GetGoodsItemID(const int iIndex)const;

    /**
    * @brief 获取商品数量
    */
    int GetGoodsItemNum(const int iIndex)const;

    /**
    * @brief 获取商品购买价格
    */
    int GetGoodsBuyPrice(const int iIndex)const;

    /**
    * @brief 获取商品出售价格
    */
    int GetGoodsSellPrice(const int iIndex)const;

public:
private:
private:
    /*!< 商品 */
    vector<ShopConfig> m_vecGoods;
};




#endif // __SHOP_H__