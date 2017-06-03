#ifndef __MAP_H__
#define __MAP_H__

#include "Struct.h"

/**
 * @brief ��ͼ��
 */
class Map
{
public:
    Map();
    ~Map();

public:
    /**
    * @brief �޵�ͼ
    */
    static const Map &GetNoMap();

public:
    /**
     * @brief ��ʼ��
     */
    bool Init(const Map &oMap);

    /**
     * @brief ��ʼ��
     */
    bool Init(const int iID, const string sName, const vector<int> &vMapActionID);
public:
    SET_GET(int,         i,ID,         m_stMapData.iID)
    SET_GET(string,      s,Name,       m_stMapData.sName)
    SET_GET(vector<int>&,v,MapActionID,m_stMapData.vMapActionID)
private:
    /**
     * @brief ��ͼ���ݽṹ��
     */
    struct MapData
    {
        /*!< ��� */
        int iID;

        /*!< ���� */
        string sName;

        /*!< ��Ϊ */
        vector<int> vMapActionID;
    };
private:
    //*!< ��ͼ���� */
    MapData m_stMapData;
};


#endif // __MAP_H__

