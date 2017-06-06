#ifndef __PROPERTYFRAME_H__
#define __PROPERTYFRAME_H__

#include "Singleton.h"
#include "Frame.h"



/**
 * @brief ���������Կ�
 */
class PropertyFrame : public Frame, public Singleton<PropertyFrame>
{
public:
    PropertyFrame();
    ~PropertyFrame();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init(const FrameConfig &stConfig);


public:
    /**
     * @brief ���¿�
     */
    virtual void Update();

public:
    inline void SetHp(const int iHp) { m_iHp = iHp; }
    inline void SetMaxHp(const int MaxHp) { m_iMaxHp = MaxHp; }
    inline void SetMoney(const int iMoney) { m_iMoney = iMoney; }
    inline void SetLevel(const int iLevel) { m_iLevel = iLevel; }
    inline void SetExp(const int iExp) { m_iExp = iExp; }
    inline void SetTotalExp(const int iTotalExp) { m_iTotalExp = iTotalExp; }
    inline void SetBag(const int iBag) { m_iBag = iBag; }
    inline void SetTotalBag(const int iTotalBag) { m_iTotalBag = iTotalBag; }
private:
    /*!< Ѫ�� */
    int m_iHp;

    /*!< ���Ѫ�� */
    int m_iMaxHp;

    /*!< ���� */
    int m_iMoney;

    /*!< �ȼ� */
    int m_iLevel;

    /*!< ��ǰ���� */
    int m_iExp;

    /*!< �¼����� */
    int m_iTotalExp;

    /*!< ������Ʒ���� */
    int m_iBag;

    /*!< ���������� */
    int m_iTotalBag;
};


#endif // __PROPERTYFRAME_H__


