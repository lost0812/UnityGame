
#ifndef __MONSTERCONFIG_LOADER_H__
#define __MONSTERCONFIG_LOADER_H__



#define g_MonsterConfigLoader MonsterConfigLoader::GetInstance()

#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;

/**
 * @brief ��������
 */
enum MonsterType
{
		/*!< �º� */
		MONSTER_TYPE_GENTLE = 1,

		/*!< ���� */
		MONSTER_TYPE_NEUTRAL = 2,

		/*!< �ж� */
		MONSTER_TYPE_HOSTIL = 3,

};

/**
 * @brief ��������
 */
struct MonsterConfig
{	
		/*!< ��� */
		int iID;
		
		/*!< ���� */
		MonsterType eType;
		
		/*!< �������� */
		int iMaxHp;
		
		/*!< ������ */
		int iAttack;
		
		/*!< ������ */
		int iDefance;
	
	
		/*!< ���� */
		string sName;
		
		/*!< ���� */
		string sDescription;
	
	
		/*!< ���� */
		vector< int > veciDropID;
	

};

class MonsterConfigLoader : public Singleton<MonsterConfigLoader>
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
	const vector<MonsterConfig> &GetAllConfig();
	
	/**
	 * @brief ͨ��������ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByIndex(const unsigned int uIndex);
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByID(const int iID);
		
	/**
	 * @brief ͨ�����ͻ�ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByType(const MonsterType eType);
		
	/**
	 * @brief ͨ���������޻�ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByMaxHp(const int iMaxHp);
		
	/**
	 * @brief ͨ����������ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByAttack(const int iAttack);
		
	/**
	 * @brief ͨ����������ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByDefance(const int iDefance);
	
	
	/**
	 * @brief ͨ�����ֻ�ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const MonsterConfig *GetMonsterConfigByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<MonsterConfig> m_vecRecords;
};

#endif //__MONSTERCONFIG_LOADER_H__
