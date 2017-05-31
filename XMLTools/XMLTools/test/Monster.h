
#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <string>

	#include "ActorData.h"


	/*<! ����������*/
	#define DROP_MAX 10




using std::string;

/**
 * @brief ����
 */
class Monster 	:public ActorData
{
public:
    Monster();
    ~Monster();
public:
    /**
     * @brief �ն���
     */
    static const Monster &GetNoMonster();
public:
	/**
	 * @brief ��������
	 */
	enum MonsterType
	{
		/*<! �º�*/
		MONSTER_TYPE_GENTLE = 0
,
		/*<! ����*/
		MONSTER_TYPE_NEUTRAL = 1
,
		/*<! �ж�*/
		MOSTER_TYPE_HOSTIL = 2

	};


	
	/**
	 * @brief ����
	 */
	struct Drops
	{
		/*<! ������*/
		int iID;

		/*<! ��������*/
		int iNum;

	}


public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const Monster &oMonster);
    
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
	 * @brief ��ȡ��������
	 */
	inline const Monster::MonsterType GetType() const{return m_eType;}

	/**
	 * @brief ��ȡ����
	 */
	inline const string GetDescription() const{return m_iDescription;}

	
	/**
	 * @brief ���ù�������
	 */
	inline void SetType(const Monster::MonsterType eType){m_eType = eType;}
	
	/**
	 * @brief ��������
	 */
	inline void SetDescription(const string iDescription){m_iDescription = iDescription;}


	/**
	 * @brief ��ȡ��������
	 */
	int GetDropsNum() const;


	/**
	 * @brief ��ȡ����
	 */
	bool GetDrops(const int iIndex, Drop &stDrops) const;


	/**
	 * @brief ��ӵ���
	 */
	bool AddDrops(Drop stDrops);


	/**
	 * @brief �Ƴ�����
	 */
	bool RemoveDrops(int iIndex);

#struct_set#
	
		
	/**
	 * @brief ��ȡ������
	 */
	int GetDropsID(const int iIndex) const

	/**
	 * @brief ��ȡ��������
	 */
	int GetDropsNum(const int iIndex) const

		
private:  

	/*<! ��������*/
	Monster::MonsterType m_eType;

	/*<! ����*/
	string m_iDescription;


	/*<! ����*/
	Drop m_astDrops[DROP_MAX];
	int m_stDropsRef;

};

#endif //__MONSTER_H__
