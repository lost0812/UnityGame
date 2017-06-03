#ifndef __EQUIPMENT__H__
#define __EQUIPMENT__H__

#include "Item.h"

/**
* @brief װ����
*/
class Equipment : public Item
{
public:
    /**
    * @brief װ������
    */
    enum EquipmentType
    {
        /*!< ���� */
        EQUIPMENT_TYPE_WEAPON = 0,

        /*!< ���� */
        EQUIPMENT_TYPE_AEMOR = 1,

        /*!< ��Ʒ */
        EQUIPMENT_TYPE_ACCESSORY = 2,

        /*!< �������ֵ */
        EQUIPMENT_TYPE_MAX = 3,
    };
public:
	Equipment();
	~Equipment();
public:

    /**
    * @brief ��ʼ��
    */
    virtual bool Init(const Equipment &oEquipment);
    
    /**
	 * @brief ��ʼ��
	 */
	virtual bool Init( 
        const int iID, 
        const Item::ItemType eType,
        const string &sName,
        const string &sDescription,
        const Equipment::EquipmentType eEquipmentType,
        const int iMaxHp,
        const int iAttack,
        const int iDefance );


private:
    /**
    * @brief װ������
    */
    struct EquipmentData
    {
        /*<! ���� */
        Equipment::EquipmentType eType;

        /*<! ������������ */
        int iMaxHp;

        /*<! ���ӹ����� */
        int iAttack;

        /*<! ���ӷ����� */
        int iDefance;
    };
private:
	/*!< װ������ */
    EquipmentData m_stEquipmentData;
public:
    SET_GET(Equipment::EquipmentType, e, Type, m_stEquipmentData.eType);
    SET_GET(int, i, MaxHp, m_stEquipmentData.iMaxHp);
    SET_GET(int, i, Attack, m_stEquipmentData.iAttack);
    SET_GET(int, i, Defance, m_stEquipmentData.iDefance);
};



#endif
