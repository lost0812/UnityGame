
#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <string>




/*<! ��������*/
#define MAX_CONTAINER_CAPACITY 30




using std::string;

/**
 * @brief ����
 */
class Container 
{
public:
    Container();
    ~Container();
public:
    /**
     * @brief �ն���
     */
    static const Container &GetNoContainer();
public:


	
	/**
	 * @brief ��Ԫ������
	 */
	struct Cell
	{
		/*<! ���*/
		int iID;

		/*<! ��Ʒ���*/
		int iItemID;

		/*<! ��Ʒ����*/
		int iItemNum;

		/*<! ��Ʒ������*/
		int iUnitCapacity;

	};


public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const Container &oContainer);
    
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
	inline const int GetID() const{return m_iID;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int iID){m_iID = iID;}




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
	 * @brief �Ƴ���������
	 */
	bool RemoveCell(const int iIndex);


		
	/**
	 * @brief ��ȡ���
	 */
	int GetCellID(const int iIndex) const;

	/**
	 * @brief ��ȡ��Ʒ���
	 */
	int GetCellItemID(const int iIndex) const;

	/**
	 * @brief ��ȡ��Ʒ����
	 */
	int GetCellItemNum(const int iIndex) const;

	/**
	 * @brief ��ȡ��Ʒ������
	 */
	int GetCellUnitCapacity(const int iIndex) const;

		
private:  

	/*<! ���*/
	int m_iID;



	/*<! ��������*/
	CellData m_astCell[MAX_CONTAINER_CAPACITY];
	/*<! ������������*/
	int m_iCellRef;

};

#endif //__CONTAINER_H__
