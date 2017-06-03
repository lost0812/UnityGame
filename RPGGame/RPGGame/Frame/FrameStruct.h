#ifndef __FRAMESTRUCT_H__
#define __FRAMESTRUCT_H__

/**
 * @brief �������
 */
namespace frame_data
{
    /**
     * @brief ���������Կ�����
     */
    struct PropertyFrameData
    {
        /*!< Ѫ�� */
        int iHp;

        /*!< ���Ѫ�� */
        int iMaxHp;

        /*!< ���� */
        int iMoney;

        /*!< �ȼ� */
        int iLevel;

        /*!< ��ǰ���� */
        int iExp;

        /*!< �¼����� */
        int iTotalExp;

        /*!< ������Ʒ���� */
        int iBag;

        /*!< ���������� */
        int iTotalBag;
    };

}

#endif // __FRAMESTRUCT_H__
