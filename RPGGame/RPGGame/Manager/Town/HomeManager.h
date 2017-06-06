#ifndef __HOMEMANAGER_H__
#define __HOMEMANAGER_H__

#include <string.h>

#include "Singleton.h"
#include "Bag.h"

using std::string;

class HomeManager : public Singleton<HomeManager>
{
public:
    HomeManager();
    virtual ~HomeManager();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init();

    /**
    * @brief ����
    */
    virtual bool Save(const string sFile);

    /**
    * @brief ����
    */
    virtual bool Load(const string sFile);
public:
    /**
     * @brief ��ȡ�ֿ�
     */
    const Bag &GetStorage();
    
    /**
     * @brief ��Ž��ֿ�
     */
    bool AddToStorage(const int iItemID, const int iItemNum);

    /**
    * @brief �Ӳֿ����
    */
    bool ReduceFromStorage(const int iItemID, const int iItemNum);

    /**
     * @brief �Ӳֿ�ȡ��
     */
    int RemoveFromStorage(const int iItemID);

private:
    Bag m_oStorage;
};



#endif // __HOMEMANAGER_H__


