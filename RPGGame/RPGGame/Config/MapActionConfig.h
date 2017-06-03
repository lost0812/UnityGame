
#ifndef __MAPACTION_LOADER_H__
#define __MAPACTION_LOADER_H__



#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;

/**
 * @brief ��ͼ��Ϊ����
 */
enum MapActionType
{
		/*!< �ɼ� */
		MAP_ACTION_TYPE_COLLECTION = 1,

		/*!< ���� */
		MAP_ACTION_TYPE_HANTING = 2,

};

/**
 * @brief ��ͼ��Ϊ����
 */
struct MapAction
{	
		/*!< ��� */
		int iID;
		
		/*!< ���� */
		MapActionType eType;
		
		/*!< ��������ֵ */
		int iPower_cost;
		
		/*!< ����ʱ�� */
		int iTime_cost;
		
		/*!< ������ */
		int iMaxtime;
		
		/*!< �ָ��ٶ� */
		int iRecovery;
	
	
		/*!< ���� */
		string sName;
		
		/*!< ���� */
		string sDescription;
	
	
		/*!< ���� */
		vector< int > veciMonster_id;
		
		/*!< ���� */
		vector< int > veciDrop_id;
	

};

class MapActionConfig : public Singleton<MapActionConfig>
{
public:
	/**
	 * @brief ��ʼ��
	 */
    bool Init();
	
public:
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const MapAction *GetMapActionByID(const int iID);
		
	/**
	 * @brief ͨ�����ͻ�ȡ����
	 */
	const MapAction *GetMapActionByType(const MapActionType eType);
		
	/**
	 * @brief ͨ����������ֵ��ȡ����
	 */
	const MapAction *GetMapActionByPower_cost(const int iPower_cost);
		
	/**
	 * @brief ͨ������ʱ���ȡ����
	 */
	const MapAction *GetMapActionByTime_cost(const int iTime_cost);
		
	/**
	 * @brief ͨ����������ȡ����
	 */
	const MapAction *GetMapActionByMaxtime(const int iMaxtime);
		
	/**
	 * @brief ͨ���ָ��ٶȻ�ȡ����
	 */
	const MapAction *GetMapActionByRecovery(const int iRecovery);
	
	
	/**
	 * @brief ͨ�����ֻ�ȡ����
	 */
	const MapAction *GetMapActionByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const MapAction *GetMapActionByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<MapAction> m_vecRecords;
};

#endif //__MAPACTION_LOADER_H__
