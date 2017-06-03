#ifndef __MAPLOADER_H__
#define __MAPLOADER_H__


#include "Singleton.h"
#include "Loader.h"
#include "Map.h"

/**
 * @brief ��ͼ���ü���
 */
class MapLoader : public Loader, public Singleton<MapLoader>
{
public:
    MapLoader();
    ~MapLoader();

public:   
    /**
     * @brief ���������ļ�
     */
    virtual bool Load() override;

public:
    /**
     * @brief ��ȡ����
     */
    int GetMapNum()const;

    /**
     * @brief ��ȡ����
     */
    const Map &GetMapByID(const int iID)const;

private:
    /*!< ������ͼӳ�� */
    map<int, Map> m_mapMaps;
};



#endif // __MAPLOADER_H__


