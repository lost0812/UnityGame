
#ifndef __CELLDATA_H__
#define __CELLDATA_H__

#include <string>





using std::string;

/**
 * @brief ��Ԫ������
 */
class CellData
{
public:

public:
    CellData();
    ~CellData();
public:
    /**
     * @brief �ն���
     */
    static const CellData &GetNoCellData();
public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const CellData &oCellData);
    
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
	 * @brief ��ȡ��Ʒ���
	 */
	inline const int &GetItemID() const{return m_iItemID;}

	/**
	 * @brief ��ȡ��Ʒ����
	 */
	inline const int &GetItemNum() const{return m_iItemNum;}

	/**
	 * @brief ��ȡ��Ʒ������
	 */
	inline const int &GetUnitCapacity() const{return m_iUnitCapacity;}


	/**
	 * @brief ʹ�ñ��
	 */
	inline int &UseID(){return m_iID;}

	/**
	 * @brief ʹ����Ʒ���
	 */
	inline int &UseItemID(){return m_iItemID;}

	/**
	 * @brief ʹ����Ʒ����
	 */
	inline int &UseItemNum(){return m_iItemNum;}

	/**
	 * @brief ʹ����Ʒ������
	 */
	inline int &UseUnitCapacity(){return m_iUnitCapacity;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int &iID){m_iID = iID;}
	
	/**
	 * @brief ������Ʒ���
	 */
	inline void SetItemID(const int &iItemID){m_iItemID = iItemID;}
	
	/**
	 * @brief ������Ʒ����
	 */
	inline void SetItemNum(const int &iItemNum){m_iItemNum = iItemNum;}
	
	/**
	 * @brief ������Ʒ������
	 */
	inline void SetUnitCapacity(const int &iUnitCapacity){m_iUnitCapacity = iUnitCapacity;}







private:  

	/*<! ���*/
	int m_iID;

	/*<! ��Ʒ���*/
	int m_iItemID;

	/*<! ��Ʒ����*/
	int m_iItemNum;

	/*<! ��Ʒ������*/
	int m_iUnitCapacity;



};

#endif //__CELLDATA_H__
