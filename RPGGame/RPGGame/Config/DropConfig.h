
#ifndef __DROP_LOADER_H__
#define __DROP_LOADER_H__



#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;



/**
 * @brief ����
 */
struct Drop
{	
		/*!< ��� */
		int iID;
		
		/*!< ��Ʒ��� */
		int iItem_id;
		
		/*!< ��Ʒ���� */
		int iItem_num;
	



};

class DropConfig : public Singleton<DropConfig>
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
	const Drop *GetDropByID(const int iID);
		
	/**
	 * @brief ͨ����Ʒ��Ż�ȡ����
	 */
	const Drop *GetDropByItem_id(const int iItem_id);
		
	/**
	 * @brief ͨ����Ʒ������ȡ����
	 */
	const Drop *GetDropByItem_num(const int iItem_num);
	

private:
	/*!< �������� */
    vector<Drop> m_vecRecords;
};

#endif //__DROP_LOADER_H__
