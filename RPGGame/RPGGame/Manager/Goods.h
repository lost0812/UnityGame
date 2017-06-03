#ifndef __GOODS_H__
#define __GOODS_H__

#include "Struct.h"

class Goods
{
public:
    Goods(const Goods &stGoods);
    Goods(const int iID, const int iItemID, const int iItemNum, const int iBuyPrice, const int iSellPrice);
    ~Goods();
public:
    bool Buy(const int iItemNum);
    bool Sell(const int iItemNum);
public:
    SET_GET(int, i, ID,        m_stGoodsData.iID)
    SET_GET(int, i, ItemID,    m_stGoodsData.iItemID)
    SET_GET(int, i, ItemNum,   m_stGoodsData.iItemNum)
    SET_GET(int, i, BuyPrice,  m_stGoodsData.iBuyPrice)
    SET_GET(int, i, SellPrice, m_stGoodsData.iSellPrice)
private:
    /**
    * @brief ��Ʒ����
    */
    struct GoodsData
    {
        /*!< ��Ʒ��� */
        int iID;

        /*!< ��Ʒ��� */
        int iItemID;

        /*!< ��Ʒ��� */
        int iItemNum;

        /*!< ���ι���۸� */
        int iBuyPrice;

        /*!< ���γ��ۼ۸� */
        int iSellPrice;
    };
private:
    GoodsData m_stGoodsData;
};

#endif // __GOODS_H__

