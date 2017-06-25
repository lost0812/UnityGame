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
    const vector<ShopConfig> &GetAllGoods()const;

    /**
    * @brief ������Ʒ
    */
    bool BuyGoods(const int iGoodsID, const int iNum, int &iPrice, int &iCapacity);

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
private:
private:
    /*!< ��Ʒ */
    vector<ShopConfig> m_vecGoods;
};




#endif // __SHOP_H__