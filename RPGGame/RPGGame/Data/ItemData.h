
#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

#include <string>





using std::string;

/**
 * @brief ��Ʒ����
 */
class ItemData
{
public:

public:
    ItemData();
    ~ItemData();
public:
    /**
     * @brief �ն���
     */
    static const ItemData &GetNoItemData();
public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const ItemData &oItemData);
    
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
	 * @brief ��ȡ����
	 */
	inline const int &GetNum() const{return m_iNum;}


	/**
	 * @brief ʹ�ñ��
	 */
	inline int &UseID(){return m_iID;}

	/**
	 * @brief ʹ������
	 */
	inline int &UseNum(){return m_iNum;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int &iID){m_iID = iID;}
	
	/**
	 * @brief ��������
	 */
	inline void SetNum(const int &iNum){m_iNum = iNum;}








private:  

	/*<! ���*/
	int m_iID;

	/*<! ����*/
	int m_iNum;



};

#endif //__ITEMDATA_H__
