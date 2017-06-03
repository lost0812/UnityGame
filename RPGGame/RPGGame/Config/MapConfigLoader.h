
#ifndef __MAPCONFIG_LOADER_H__
#define __MAPCONFIG_LOADER_H__



#define g_MapConfigLoader MapConfigLoader::GetInstance()

#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;



/**
 * @brief ��ͼ����
 */
struct MapConfig
{	
		/*!< ��� */
		int iID;
	
	
		/*!< ���� */
		string sName;
	
	
		/*!< �ж� */
		vector< int > veciActionID;
	

};

class MapConfigLoader : public Singleton<MapConfigLoader>
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
	const vector<MapConfig> &GetAllConfig();
	
	/**
	 * @brief ͨ��������ȡ����
	 */
	const MapConfig *GetMapConfigByIndex(const unsigned int uIndex);
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const MapConfig *GetMapConfigByID(const int iID);
	
	
	/**
	 * @brief ͨ�����ƻ�ȡ����
	 */
	const MapConfig *GetMapConfigByName(const string sName);
	
private:
	/*!< �������� */
    vector<MapConfig> m_vecRecords;
};

#endif //__MAPCONFIG_LOADER_H__
