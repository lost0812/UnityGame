#ifndef __MAPACTIONLOADER_H__
#define __MAPACTIONLOADER_H__

#include <map>

#include "Singleton.h"

#include "Loader.h"
#include "MapAction.h"

using std::map;
using std::make_pair;

/**
 * @brief ��ͼ��Ϊ���ü���
 */
class MapActionLoader :public Singleton<MapActionLoader>,public Loader
{
public:
    MapActionLoader();
    ~MapActionLoader();
public:
    /**
     * @brief ���������ļ�
     */
    virtual bool Load() override;

public:
    /**
     * @brief ͨ����Ż�ȡ��ͼ��Ϊ
     */
    const MapAction &GetMapActionByID(const int iID)const;

    /**
     * @brief ��ȡ��ͼ��Ϊ����
     */
    int GetMapActionNum()const;
private:
    /*!< ������ͼ��Ϊӳ�� */
    map<int, MapAction> m_mapMapActions;
};


#endif // __MAPACTIONLOADER_H__


