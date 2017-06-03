#ifndef __MAPACTION_H__
#define __MAPACTION_H__

#include "Struct.h"

/**
 * @brief ��ͼ��Ϊ��
 */
class MapAction
{
public:
    /**
     * @brief ��ͼ��Ϊ����
     */
    enum MapActionType
    {
        /*!< ����Ϊ */
        MAPACTION_TYPE_NO_MAP = 0,

        /*!< ��Դ�����Ϊ */
        MAPACTION_TYPE_RESOURCE = 1,

        /*!< ���������Ϊ */
        MAPACTION_TYPE_MONSTER = 2,
    };
public:
    MapAction();
    virtual ~MapAction();
public:
    /**
    * @brief �޵�ͼ��Ϊ
    */
    static const MapAction &GetNoMapAction();
public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const MapAction &oMapAction);

    /**
     * @brief ��ʼ��
     */
    virtual bool Init(
        const int iID,
        const MapAction::MapActionType eType,
        const string sName,
        const string sDescription,
        const int iPowerCost,
        const int iTimeCost,
        const int iMaxTime,
        const int iRecovery,
        const vector<int> &vMonsterID,
        const vector<int> &vDropID);


public:
    SET_GET(int,          i, ID,          m_stMapActionData.iID)
    SET_GET(MapAction::MapActionType, e, Type, m_stMapActionData.eType)
    SET_GET(string,       s, Name,        m_stMapActionData.sName)
    SET_GET(string,       s, Description, m_stMapActionData.sDescription)
    SET_GET(int,          i, PowerCost,   m_stMapActionData.iPowerCost)
    SET_GET(int,          i, TimeCost,    m_stMapActionData.iTimeCost)
    SET_GET(int,          i, MaxTime,     m_stMapActionData.iMaxTime)
    SET_GET(int,          i, Recovery,    m_stMapActionData.iRecovery)
    SET_GET(vector<int>&, v, MonsterID,   m_stMapActionData.vMonsterID)
    SET_GET(vector<int>&, v, DropID,      m_stMapActionData.vDropID)

private:
    /**
     * @brief ��ͼ��Ϊ���ݽṹ��
     */
    struct MapActionData
    {
        /*!< ��� */
        int iID;

        /*!< ���� */
        MapAction::MapActionType eType;

        /*!< ���� */
        string sName;

        /*!< ���� */
        string sDescription;

        /*!< ��������ֵ */
        int iPowerCost;

        /*!< ����ʱ��ֵ */
        int iTimeCost;

        /*!< ������ */
        int iMaxTime;

        /*!< �ָ��ٶ� */
        int iRecovery;

        /*!< ������ */
        vector<int> vMonsterID;

        /*!< ������ */
        vector<int> vDropID;
    };
private:
    /*!< ��ͼ��Ϊ���� */
    MapActionData m_stMapActionData;
};


#endif // __MAPACTION_H__
