#ifndef __UNIT_H__
#define __UNIT_H__

#include "Item.h"

class Unit
{
public:
    Unit();
    virtual ~Unit();
public:   
    /**
     * @brief ��ʼ������
     */
    virtual bool Init( Unit &oUnit);

    /**
     * @brief ��ʼ������
     */
    virtual bool Init(
        const int iID, 
        const int iItemID, 
        const int iItemNum, 
        const int iUnitCapacity);

    /**
     * @brief ����
     */
    virtual bool Save( int &iLength, char *csBuffer )const ; 

    /**
     * @brief ����
     */
    virtual bool Load( int &iLength, const char *const csBuffer );

    /**
     * @brief �����Ʒ
     */
    virtual bool Add(const int iItemNum);

    /**
     * @brief ������Ʒ
     */
    virtual bool Reduce(const int iItemNum);
    
public:
    SET_GET(int, i, ID,           m_stUnitData.iID);
    SET_GET(int, i, ItemID, m_stUnitData.iItemID);
    SET_GET(int, i, ItemNum, m_stUnitData.iItemNum);
    SET_GET(int, i, UnitCapacity, m_stUnitData.iUnitCapacity);
private:
    /**
    * @brief ��Ԫ������
    */
    struct UnitData
    {
        /*!< ��� */
        int iID;

        /*!< ��Ʒ��� */
        int iItemID;

        /*!< ��Ʒ���� */
        int iItemNum;

        /*!< ��Ʒ������ */
        int iUnitCapacity;
    };
private:
    UnitData m_stUnitData;
};



#endif // __UNIT_H__

