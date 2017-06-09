
#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <string>


using std::string;

/**
 * @brief ����
 */
class Container
{
public:

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

#endif //__CONTAINER_H__
