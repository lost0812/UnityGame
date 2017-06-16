#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "ContainerData.h"

/**
 * @brief ������
 */
class Container
{
public:
    Container();
	virtual ~Container();
public:
    /**
     * @brief ��ʼ��
     */
    bool Init(ContainerData *pstContainerData);

public:
    /**
     * @brief ��ȡ��������
     */
    int GetCapacity() const;

    /**
     * @brief ��ȡ����ʹ����
     */
    int GetUsedCapacity() const;
    /**
     * @brief �����Ʒ
     */
    int Add(const int iItemID, const int iNumber);

    /**
     * @brief ���������Ʒ
     */
    int TryAdd(const int iItemID, const int iNumber) const;

    /**
    * @brief ǿ�������Ʒ
    */
    void AddForce(const int iItemID, const int iNumber);

    /**
    * @brief �Ƴ���Ʒ
    */
    int Remove(const int iItemID, const int iNumber);

    /**
    * @brief �Ƴ���Ʒ
    */
    int TryRemove(const int iItemID, const int iNumber);

    /**
    * @brief �Ƴ���Ʒ
    */
    void RemoveForce(const int iItemID, const int iNumber);

    /**
     * @brief ��ȡ��Ʒ����
     */
    int GetItemNumByItemID(const int iItemID) const;

    /**
    * @brief ��ȡ��Ʒ����
    */
    int GetItemCapacityByItemID(const int iItemID) const;

public:
    /**
     * @brief ��ȡ��������
     */
    inline const ContainerData *GetContainerData() const { return m_pstContainerData; }

    /**
    * @brief ʹ����������
    */
    inline ContainerData *UseContainerData() { return m_pstContainerData; }

    /**
    * @brief ������������
    */
    inline void SetContainerData(ContainerData *pstContainerData) { m_pstContainerData = pstContainerData; }

private:
    /*!< �������� */
    ContainerData *m_pstContainerData;
};


#endif // __CONTAINER_H__

