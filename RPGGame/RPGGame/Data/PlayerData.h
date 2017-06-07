
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
	 * @brief ��ȡ��ǰ����ֵ
	 */
	inline const int GetHp() const{return m_iHp;}

	/**
	 * @brief ��ȡ�������ֵ
	 */
	inline const int GetMaxHp() const{return m_iMaxHp;}

	/**
	 * @brief ��ȡ����������
	 */
	inline const int GetBaseAttack() const{return m_iBaseAttack;}

	/**
	 * @brief ��ȡ����������
	 */
	inline const int GetBaseDefance() const{return m_iBaseDefance;}

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
	 * @brief ��ȡ����
	 */
	inline const int GetWeapon() const{return m_iWeapon;}

	/**
	 * @brief ��ȡ����
	 */
	inline const int GetArmor() const{return m_iArmor;}

	/**
	 * @brief ��ȡ��Ʒ
	 */
	inline const int GetAccessory() const{return m_iAccessory;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int iID){m_iID = iID;}
	
	/**
	 * @brief ���õ�ǰ����ֵ
	 */
	inline void SetHp(const int iHp){m_iHp = iHp;}
	
	/**
	 * @brief �����������ֵ
	 */
	inline void SetMaxHp(const int iMaxHp){m_iMaxHp = iMaxHp;}
	
	/**
	 * @brief ���û���������
	 */
	inline void SetBaseAttack(const int iBaseAttack){m_iBaseAttack = iBaseAttack;}
	
	/**
	 * @brief ���û���������
	 */
	inline void SetBaseDefance(const int iBaseDefance){m_iBaseDefance = iBaseDefance;}
	
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
	 * @brief ��������
	 */
	inline void SetWeapon(const int iWeapon){m_iWeapon = iWeapon;}
	
	/**
	 * @brief ���÷���
	 */
	inline void SetArmor(const int iArmor){m_iArmor = iArmor;}
	
	/**
	 * @brief ������Ʒ
	 */
	inline void SetAccessory(const int iAccessory){m_iAccessory = iAccessory;}








private:  

	/*<! ���*/
	int m_iID;

	/*<! ��ǰ����ֵ*/
	int m_iHp;

	/*<! �������ֵ*/
	int m_iMaxHp;

	/*<! ����������*/
	int m_iBaseAttack;

	/*<! ����������*/
	int m_iBaseDefance;

	/*<! Ǯ*/
	int m_iMoney;

	/*<! �ȼ�*/
	int m_iLevel;

	/*<! ��ǰ��þ���*/
	int m_iExp;

	/*<! ����*/
	int m_iWeapon;

	/*<! ����*/
	int m_iArmor;

	/*<! ��Ʒ*/
	int m_iAccessory;



};

#endif //__PLAYERDATA_H__
