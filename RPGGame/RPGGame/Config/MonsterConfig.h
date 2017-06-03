
#ifndef __MONSTER_LOADER_H__
#define __MONSTER_LOADER_H__



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
struct Monster
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
		vector< int > veciDrop_id;
	

};

class MonsterConfig : public Singleton<MonsterConfig>
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
	const Monster *GetMonsterByID(const int iID);
		
	/**
	 * @brief ͨ�����ͻ�ȡ����
	 */
	const Monster *GetMonsterByType(const MonsterType eType);
		
	/**
	 * @brief ͨ���������޻�ȡ����
	 */
	const Monster *GetMonsterByMaxHp(const int iMaxHp);
		
	/**
	 * @brief ͨ����������ȡ����
	 */
	const Monster *GetMonsterByAttack(const int iAttack);
		
	/**
	 * @brief ͨ����������ȡ����
	 */
	const Monster *GetMonsterByDefance(const int iDefance);
	
	
	/**
	 * @brief ͨ�����ֻ�ȡ����
	 */
	const Monster *GetMonsterByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const Monster *GetMonsterByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<Monster> m_vecRecords;
};

#endif //__MONSTER_LOADER_H__
