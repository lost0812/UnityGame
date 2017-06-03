
#ifndef __FRAME_LOADER_H__
#define __FRAME_LOADER_H__


/*!< ѡ��������� */
#define MAX_OPTION_NUM 5


#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;



/**
 * @brief ѡ��
 */
struct Option
{
	/*!< ֪ͨ���� */
	int iNotify;

	/*!< ��Ӧ��ID */
	int iFrame_id;


	/*!< ѡ������ */
	string sDescription;

};

/**
 * @brief ������
 */
struct Frame
{	
		/*!< ��� */
		int iID;
		
		/*!< ��Ӧ���� */
		int iHandle_id;
	
	
		/*!< ���� */
		string sName;
		
		/*!< ���� */
		string sDescription;
	


		/*!< ѡ�� */
		vector<Option> vecOption;

};

class FrameConfig : public Singleton<FrameConfig>
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
	const Frame *GetFrameByID(const int iID);
		
	/**
	 * @brief ͨ����Ӧ�����ȡ����
	 */
	const Frame *GetFrameByHandle_id(const int iHandle_id);
	
	
	/**
	 * @brief ͨ�����ƻ�ȡ����
	 */
	const Frame *GetFrameByName(const string sName);
		
	/**
	 * @brief ͨ��������ȡ����
	 */
	const Frame *GetFrameByDescription(const string sDescription);
	
private:
	/*!< �������� */
    vector<Frame> m_vecRecords;
};

#endif //__FRAME_LOADER_H__
