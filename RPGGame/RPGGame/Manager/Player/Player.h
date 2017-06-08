#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Actor.h"
#include "Struct.h"
#include "Bag.h"
#include "Equipment.h"
#include "Goods.h"

#include "PlayerData.h"
/**
* @brief �����
*/
class Player
{
     /**
      * @brief װ������
      */
//      enum EquipmentOperator
//      {
//          /*!< װ�� */
//          EQUIPMENT_OPERATOR_PUTON,
//          /*!< ж�� */
//          EQUIPMENT_OPERATOR_GETOFF,
//          /*!< �滻 */
//          EQUIPMENT_OPERATOR_CHANGE
//      };
 
//      /**
//       * @brief �ж�װ��λ��״̬
//       */
//      struct EquipmentState
//      {
//          /*!< �Ƿ���װ����true��װ����false ��װ�� */
//          bool bIsEquip;
//          /*!< װ����Ϣ */
//          Equipment oEquipment;
//      };
 public:
 	Player();
 	~Player();
 public://-�������----------------------------------------------------//
     /**
      * @brief ��ʼ��
      */
     virtual bool Init();

     /**
      * @brief ����
      */
     virtual bool Save(int &iLength, char *csBuffer)const;
 
     /**
      * @brief ����
      */
     virtual bool Load(int &iLength, const char *const csBuffer);
 
     /**
      * @brief װ��װ������ж��װ��
      */
//     EquipmentOperator Equip(
//         const EquipmentOperator eEquipmentOperator,
//         const Equipment &oNewEquipment,
//         Equipment &oOldEuipment);

public://-ս�����----------------------------------------------------//
    /**
     * @brief �Ƿ�����
     */
    virtual bool IsDie()const;

    /**
    * @brief �����˺�
    */
    virtual void Defance(const int iDamage);
 
    /**
    * @brief �չ��˺�
    */
    virtual int Attack();

public://-��Ǯ���----------------------------------------------------//
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
     inline PlayerData &UsePlayerData() { return m_stPlayerData; }

     inline const PlayerData &GetPlayerData() const { return m_stPlayerData; }
     
     inline void SetPlayerData(PlayerData &stPlayerData) { m_stPlayerData = stPlayerData; }
 private:
     /*!< ������� */
     PlayerData m_stPlayerData;
 };


#endif // __PLAYER_H__
