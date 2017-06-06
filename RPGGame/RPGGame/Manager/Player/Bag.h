#ifndef __BAG_H__
#define __BAG_H__

#include "Unit.h"

class Bag
{
public:
    Bag();
    ~Bag();
public:
    /**
     * @brief ������
     */
    static const Bag &GetNoBag();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init(const int iID, const int iCapacity);

    /**
     * @brief ����
     */
    virtual bool Save(int &iLength, char *csBuffer)const;

    /**
     * @brief ����
     */
    virtual bool Load( int &iLength,const char *const csBuffer);
public:
    /**
    * @brief ��ȡ��ʹ�ø���
    */
    int GetUsedCapacity()const;

    /**
     * @brief �����Ʒ
     */
    bool Add(const int iItemID, const int iNumber);

    /**
     * @brief �Ƴ���Ʒ
     */
    bool Reduce(const int iItemID, const int iNumber);

    /**
     * @brief ��ȡ��Ʒ���
     */
    int GetItemID(const int iIndex)const;

    /**
     * @brief ��ȡ����
     */
    int GetItemNum(const int iIndex)const;

    /**
    * @brief ��ȡ����
    */
    int GetItemNumByItemID(const int iItemID)const;
public:
    SET_GET(int, i, Capacity, m_stContainerData.iCapacity)
private:
    /**
     * @brief ��������
     */
    struct ContainerData
    {
        /*!< ��� */
        int iID;

        /*!< ���� */
        int iCapacity;

        /*!< ʹ�� */
        int iUsed;
    };
private:
    const static int g_iMaxCapacity;

    vector<Unit> m_vUnits;
    ContainerData m_stContainerData;
};




#endif // __BAG_H__