#ifndef __MONSTERLOADER_H__
#define __MONSTERLOADER_H__


#include "Loader.h"
#include "Monster.h"
#include "Singleton.h"

/**
 * @brief ���������
 */
class MonsterLoader :public Singleton<MonsterLoader>, public Loader
{
public:
    MonsterLoader();
    ~MonsterLoader();
public:
    /**
     * @brief ���������ļ�
     */
    virtual bool Load() override;

public:
    /**
     * @brief ͨ����Ż�ȡ����
     */
    const Monster &GetMonsterByID(const int iID)const;

    /**
     * @brief ��ȡ��������
     */
    int GetMonsterNum()const;
private:
    map<int, Monster> m_mapMonsters;
};


#endif // __MONSTERLOADER_H__


