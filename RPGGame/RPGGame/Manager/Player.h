#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Actor.h"
#include "Struct.h"
#include "Bag.h"
#include "Equipment.h"
#include "Goods.h"

/**
* @brief �����
*/
class Player : public Actor
{
    /**
     * @brief װ������
     */
    enum EquipmentOperator
    {
        /*!< װ�� */
        EQUIPMENT_OPERATOR_PUTON,
        /*!< ж�� */
        EQUIPMENT_OPERATOR_GETOFF,
        /*!< �滻 */
        EQUIPMENT_OPERATOR_CHANGE
    };

    /**
     * @brief �ж�װ��λ��״̬
     */
    struct EquipmentState
    {
        /*!< �Ƿ���װ����true��װ����false ��װ�� */
        bool bIsEquip;
        /*!< װ����Ϣ */
        Equipment oEquipment;
    };
public:
	Player();
	~Player();
public://-����----------------------------------------------------//
    /**
     * @brief ��ʼ������
     */
    virtual bool Init(const Player &oPlayer);
    /**
     * @brief ��ʼ������
     */
    virtual bool Init( 
        const int iID,
        const string sName,
        const int iHp,
        const int iMaxHp,
        const int iAttack,
        const int iDefance,
        const int iMoney, 
        const int iLevel,
        const int iExp,
        const int iTotalExp);


    /**
     * @brief ����
     */
    virtual bool Save(int &iLength, char *csBuffer)const;

    /**
     * @brief ����
     */
    virtual bool Load(int &iLength, const char *const csBuffer);

    /**
     * @brief ��������ֵ
     */
    virtual void Reset();

    /**
     * @brief װ��װ������ж��װ��
     */
    EquipmentOperator Equip(
        const EquipmentOperator eEquipmentOperator,
        const Equipment &oNewEquipment,
        Equipment &oOldEuipment);

    /**
     * @brief �����˺�
     */
    virtual void Defance(const int iDamage);

    /**
     * @brief �չ��˺�
     */
    virtual int Attack();

    /**
     * @brief ��Ǯ
     */
    bool AddMoney(const int iMoney);
    /**
     * @brief ��Ǯ
     */
    bool ReduceMoney(const int iMoney);

public:

    /**
    * @brief ��ȡ�ӳɵ���������
    */
    int GetExtendMaxHp()const;

    /**
     * @brief ��ȡ�ӳɵĹ�����
     */
    int GetExtendAttack()const;

    /**
     * @brief ��ȡ�ӳɵķ�����
     */
    int GetExtendDefance()const;


public://-ģ�����ݻ�ȡ----------------------------------------------------//
    ///**
    // * @brief ��ȡ����
    // */
    //const Bag& GetBag()const;

public:
    SET_GET(int,  i, Money,    m_stPlayerData.iMoney)
    SET_GET(int,  i, Level,    m_stPlayerData.iLevel)
    SET_GET(int,  i, Exp,      m_stPlayerData.iExp)
    SET_GET(int,  i, TotalExp, m_stPlayerData.iTotalExp)
private:
    /**
     * @brief �������
     */
    struct PlayerData
    {
        /*!< Ǯ */
        int iMoney;

        /*!< �ȼ� */
        int iLevel;

        /*!< ��ǰ��þ��� */
        int iExp;

        /*!< ��һ�����辭�� */
        int iTotalExp;

    };
private:
    /*!< ������� */
    PlayerData m_stPlayerData;
    EquipmentState m_ayEquipments[Equipment::EQUIPMENT_TYPE_MAX];
};


#endif // __PLAYER_H__
