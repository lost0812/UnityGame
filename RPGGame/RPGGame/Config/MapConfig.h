
#ifndef __MAP_LOADER_H__
#define __MAP_LOADER_H__



#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;



/**
 * @brief ��ͼ����
 */
struct Map
{	
		/*!< ��� */
		int iID;
	
	
		/*!< ���� */
		string sName;
	
	
		/*!< �ж� */
		vector< int > veciAction_id;
	

};

class MapConfig : public Singleton<MapConfig>
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
	const Map *GetMapByID(const int iID);
	
	
	/**
	 * @brief ͨ�����ƻ�ȡ����
	 */
	const Map *GetMapByName(const string sName);
	
private:
	/*!< �������� */
    vector<Map> m_vecRecords;
};

#endif //__MAP_LOADER_H__
