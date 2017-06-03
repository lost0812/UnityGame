
#ifndef __MAPACTIONCONFIG_LOADER_H__
#define __MAPACTIONCONFIG_LOADER_H__



#define g_MapActionConfigLoader MapActionConfigLoader::GetInstance()

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
struct MapActionConfig
{	
		/*!< ��� */
		int iID;
		
		/*!< ���� */
		MapActionType eType;
		
		/*!< ��������ֵ */
		int iPowerCost;
		
		/*!< ����ʱ�� */
		int iTimeCost;
		
		/*!< ������ */
		int iMaxtime;
		
		/*!< �ָ��ٶ� */
		int iRecovery;
	
	
		/*!< ���� */
		string sName;
		
		/*!< ���� */
		string sDescription;
	
	
		/*!< ���� */
		vector< int > veciMonsterID;
		
		/*!< ���� */
		vector< int > veciDropID;
	

};

class MapActionConfigLoader : public Singleton<MapActionConfigLoader>
{
public:
	/**
	 * @brief ��ʼ��
	 */
    bool Init();
	
public:
	/**
	 * @brief ��ȡȫ������
	 */
	const vector<MapActionConfig> &GetAllConfig();
	
	/**
	 * @brief ͨ��������ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByIndex(const unsigned int uIndex);
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByID(const int iID);
		
	/**
	 * @brief ͨ�����ͻ�ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByType(const MapActionType eType);
		
	/**
	 * @brief ͨ����������ֵ��ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByPowerCost(const int iPowerCost);
		
	/**
	 * @brief ͨ������ʱ���ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByTimeCost(const int iTimeCost);
		
	/**
	 * @brief ͨ����������ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByMaxtime(const int iMaxtime);
		
	/**
	 * @brief ͨ���ָ��ٶȻ�ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByRecovery(const int iRecovery);
	
	
	/**
	 * @brief ͨ�����ֻ�ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const MapActionConfig *GetMapActionConfigByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<MapActionConfig> m_vecRecords;
};

#endif //__MAPACTIONCONFIG_LOADER_H__
