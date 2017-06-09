
#ifndef __CONTAINERDATA_H__
#define __CONTAINERDATA_H__

#include <string>


#include "CellData.h"



/*<! ��������*/
#define MAX_CONTAINER_CAPACITY 30


using std::string;

/**
 * @brief ����
 */
class ContainerData
{
public:

public:
    ContainerData();
    ~ContainerData();
public:
    /**
     * @brief �ն���
     */
    static const ContainerData &GetNoContainerData();
public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const ContainerData &oContainerData);
    
    /**
     * @brief �ַ�����
     */
    virtual string ToString()const;
    
    /**
     * @brief ���ַ�����
     */
    virtual bool FromString(const string sBuffer);

public:    

	/**
	 * @brief ��ȡ���
	 */
	inline const int &GetID() const{return m_iID;}


	/**
	 * @brief ʹ�ñ��
	 */
	inline int &UseID(){return m_iID;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int &iID){m_iID = iID;}




	/**
	 * @brief ��ȡ������������
	 */
	int GetCellNum() const;


	/**
	 * @brief ��ȡ��������
	 */
	bool GetCell(const int iIndex, CellData &stCell) const;


	/**
	 * @brief �����������
	 */
	bool AddCell(const CellData &stCell);


	/**
	 * @brief ʹ����������
	 */
	CellData *UseCell(const int iIndex);


	/**
	 * @brief �Ƴ���������
	 */
	bool RemoveCell(const int iIndex);

private:  

	/*<! ���*/
	int m_iID;



	/*<! ��������*/
	CellData m_astCell[MAX_CONTAINER_CAPACITY];
	/*<! ������������*/
	int m_iCellNum;

};

#endif //__CONTAINERDATA_H__
