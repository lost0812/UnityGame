#ifndef __SHOP_H__
#define __SHOP_H__

#include <vector>

#include "Goods.h"

using std::vector;

class Shop
{
public:
    /**
    * @brief �̵�����
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
    * @brief ��ʼ��
    */
    virtual bool Init();

public:
    /**
    * @brief ��ȡȫ����Ʒ��Ϣ
    */
    const vector<Goods> &GetAllGoods()const;

    /**
    * @brief ������Ʒ
    */
    bool BuyGoods(const int iIndex, const int iNum);

    /**
    * @brief ������Ʒ
    */
    bool SellGoods(const int iIndex, const int iNum);

public:
    /**
    * @brief ��ȡ��Ʒ�������
    */
    int GetGoodsNum()const;

    /**
    * @brief ��ȡ��Ʒ����Ʒ���
    */
    int GetGoodsItemID(const int iIndex)const;

    /**
    * @brief ��ȡ��Ʒ����
    */
    int GetGoodsItemNum(const int iIndex)const;

    /**
    * @brief ��ȡ��Ʒ����۸�
    */
    int GetGoodsBuyPrice(const int iIndex)const;

    /**
    * @brief ��ȡ��Ʒ���ۼ۸�
    */
    int GetGoodsSellPrice(const int iIndex)const;

public:
    SET_GET(int,      i, ID,   m_stData.iID)
    SET_GET(ShopType, e, Type, m_stData.eType)

private:
    struct ShopData
    {
        /*!< ��� */
        int iID;

        /*!< ���� */
        ShopType eType;
    };
private:
    ShopData m_stData;
    /*!< ��Ʒ */
    vector<Goods> m_vGoods;
};




#endif // __SHOP_H__