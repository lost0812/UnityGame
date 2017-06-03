#ifndef __CONTAINERDATA_H__
#define __CONTAINERDATA_H__

#include <vector>

namespace dataD
{
    /**
     * @brief ��Ԫ������
     */
    struct UnitData

    {
        /*!< ��� */
        int iID;

        /*!< ��Ʒ��� */
        int iItemID;

        /*!< ��Ʒ���� */
        int iItemNum;

        /*!< ��Ʒ������ */
        int iCapacity;
    };

    /**
     * @brief ��������
     */
    struct ContainerData 
    {
        /*!< ��� */
        int iID;

        /*!< ���� */
        int iCapacity;

        /*!< ��Ԫ������ */
        std::vector<data::UnitData> vUnits;
    };
}


#endif // __CONTAINERDATA_H__
