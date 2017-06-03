
#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include <string>




/*<! װ��������*/
#define EQUIPMENT_SLOT_SIZE 3




using std::string;

/**
 * @brief �ж�������
 */
class PlayerData 
{
public:
    PlayerData();
    ~PlayerData();
public:
    /**
     * @brief �ն���
     */
    static const PlayerData &GetNoPlayerData();
public:
	/**
	 * @brief װ����
	 */
	enum EquipmentSlotType
	{
		/*<! ����*/
		EQUIPMENT_SLOT_TYPE_WEAPON = 0,

		/*<! ����*/
		EQUIPMENT_SLOT_TYPE_AEMOR = 0,

		/*<! ��Ʒ*/
		EQUIPMENT_SLOT_TYPE_ACCESSORY = 0,

	};


	
	/**
	 * @brief װ����
	 */
	struct EquipmentSlot
	{
		/*<! ���*/
		int iEquipmentID;

	};


public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const PlayerData &oPlayerData);
    
    /**
     * @brief �ַ�����
     */
    virtual string ToString()const;
    
    /**
     * @brief ���ַ�����
     */
    virtual bool FromString(const string sBuffer);

public:    

	/**
	 * @brief ��ȡ���
	 */
	inline const int GetID() const{return m_iID;}

	/**
	 * @brief ��ȡ����ֵ
	 */
	inline const int GetHp() const{return m_iHp;}

	/**
	 * @brief ��ȡǮ
	 */
	inline const int GetMoney() const{return m_iMoney;}

	/**
	 * @brief ��ȡ�ȼ�
	 */
	inline const int GetLevel() const{return m_iLevel;}

	/**
	 * @brief ��ȡ��ǰ��þ���
	 */
	inline const int GetExp() const{return m_iExp;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int iID){m_iID = iID;}
	
	/**
	 * @brief ��������ֵ
	 */
	inline void SetHp(const int iHp){m_iHp = iHp;}
	
	/**
	 * @brief ����Ǯ
	 */
	inline void SetMoney(const int iMoney){m_iMoney = iMoney;}
	
	/**
	 * @brief ���õȼ�
	 */
	inline void SetLevel(const int iLevel){m_iLevel = iLevel;}
	
	/**
	 * @brief ���õ�ǰ��þ���
	 */
	inline void SetExp(const int iExp){m_iExp = iExp;}




	/**
	 * @brief ��ȡװ��������
	 */
	int GetEquipmentSlotNum() const;


	/**
	 * @brief ��ȡװ����
	 */
	bool GetEquipmentSlot(const int iIndex, EquipmentSlot &stEquipmentSlot) const;


	/**
	 * @brief ���װ����
	 */
	bool AddEquipmentSlot(const EquipmentSlot &stEquipmentSlot);


	/**
	 * @brief �Ƴ�װ����
	 */
	bool RemoveEquipmentSlot(const int iIndex);


		
	/**
	 * @brief ��ȡ���
	 */
	int GetEquipmentSlotEquipmentID(const int iIndex) const;

		
private:  

	/*<! ���*/
	int m_iID;

	/*<! ����ֵ*/
	int m_iHp;

	/*<! Ǯ*/
	int m_iMoney;

	/*<! �ȼ�*/
	int m_iLevel;

	/*<! ��ǰ��þ���*/
	int m_iExp;



	/*<! װ����*/
	EquipmentSlot m_astEquipmentSlot[EQUIPMENT_SLOT_SIZE];
	/*<! װ��������*/
	int m_iEquipmentSlotRef;

};

#endif //__PLAYERDATA_H__
