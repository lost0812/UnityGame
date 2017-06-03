#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include "ItemData.h"

namespace dataD
{
    /**
    * @brief �ж�������
    */
    struct ActorData
    {
        /*!< ��� */
        int iID;
        /*!< ���� */
        string sName;
        /*!< ���� */
        int iHp;
        /*!< �������� */
        int iMaxHp;
        /*!< ������ */
        int iAttack;
        /*!< ������ */
        int iDefance;
    };


    struct PlayerData
    {
        /*!< �ж��� */
        ActorData stActorData

        /*!< Ǯ */
        int iMoney;

        /*!< ��ǰ��þ��� */
        int iExp;

        /*!< ��һ�����辭�� */
        int iTotalExp;
    };
}












#endif // __PLAYERDATA_H__

