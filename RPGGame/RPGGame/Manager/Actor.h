#ifndef __ACTOR__H__
#define __ACTOR__H__

#include "Struct.h"

/**
 * @brief �ж���
 */
class Actor
{
public:
	Actor();
	~Actor();
public:
	/**
	 * @brief ��ʼ������
	 */
    virtual bool Init(const Actor &oActor);
    /**
    * @brief ��ʼ������
    */
    virtual bool Init(
        const int iID,
        const string sName,
        const int iHp,
        const int iMaxHp,
        const int iAttack,
        const int iDefance);

	/**
	 * @brief ��������ֵ
	 */
    virtual void Reset();

	/**
	 * @brief �����˺�
	 */
	virtual void Defance(const int iDamage);

	/**
	 * @brief �չ��˺�
	 */
    virtual int Attack()const;

	/**
	 * @brief �ж��Ƿ�����
	 */
    virtual bool IsDie()const;
public:
	SET_GET(int,    i, ID,      m_stActorData.iID)
	SET_GET(string, s, Name,    m_stActorData.sName)
    SET_GET(int,    i, PreHp,   m_stActorData.iPreHp)
	SET_GET(int,    i, Hp,      m_stActorData.iHp)
	SET_GET(int,    i, MaxHp,   m_stActorData.iMaxHp)
	SET_GET(int,    i, Attack,  m_stActorData.iAttack)
	SET_GET(int,    i, Defance, m_stActorData.iDefance)
private:
    /**
    * @brief �ж�������
    */
    struct ActorData
    {
        /*!< ��� */
        int iID;
        /*!< ���� */
        string sName;
        /*!< ��һ������ */
        int iPreHp;
        /*!< ���� */
        int iHp;
        /*!< �������� */
        int iMaxHp;
        /*!< ������ */
        int iAttack;
        /*!< ������ */
        int iDefance;
    };
private:
	/*!< �ж������� */
	ActorData m_stActorData;
};



#endif