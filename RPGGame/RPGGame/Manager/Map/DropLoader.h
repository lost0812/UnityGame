#ifndef __DROPLOADER_H__
#define __DROPLOADER_H__

#include "Loader.h"
#include "Drop.h"
#include "Singleton.h"

/**
 * @brief ���������
 */
class DropLoader:public Loader,public Singleton<DropLoader>
{
public:
    DropLoader();
    ~DropLoader();
public:
    /**
     * @brief ���������ļ�
     */
    virtual bool Load()override;
public:
    /**
     * @brief ͨ����Ż�ȡ����
     */
    const Drop &GetDropByID(const int iID)const;

    /**
     * @brief ������������
     */
    int GetDropNum()const;
private:
    /*!< ������������ӳ�� */
    map<int, Drop> m_mapDrop;
};



#endif // __DROPLOADER_H__
