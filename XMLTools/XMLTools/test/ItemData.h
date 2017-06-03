
#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

#include <string>




/*<! ������󳤶�*/
#define MAX_NAME_SIZE 32

/*<! ������󳤶�*/
#define MAX_DESCRIPTION_SIZE 128




using std::string;

/**
 * @brief ��Ʒ����
 */
class ItemData 
{
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
	 * @brief ��Ʒ����
	 */
	enum ItemType
	{
		/*<! ������*/
		ITEM_TYPE_NO = 0,

		/*<! ��ͨ����*/
		ITEM_TYPE_NORMAL = 1,

		/*<! ��������*/
		ITEM_TYPE_EQUIPMENT = 2,

		/*<! �������ֵ*/
		ITEM_TYPE_MAX = 3,

	};


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
	inline const int GetID() const{return m_iID;}

	/**
	 * @brief ��ȡ����
	 */
	inline const ItemType GetType() const{return m_eType;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int iID){m_iID = iID;}
	
	/**
	 * @brief ��������
	 */
	inline void SetType(const ItemType eType){m_eType = eType;}

	
	/**
	 * @brief ��ȡ����
	 */
	const char *GetName() const;
	
	/**
	 * @brief ��ȡ#string_property_comment����#
	 */
	const int GetNameLen() const;
		
	/**
	 * @brief ��ȡ����
	 */
	const char *GetDescription() const;
	
	/**
	 * @brief ��ȡ#string_property_comment����#
	 */
	const int GetDescriptionLen() const;
	
	
	/**
	 * @brief ��������
	 */
	bool SetName(const char *pName, const int iLen);
		
	/**
	 * @brief ��������
	 */
	bool SetDescription(const char *pDescription, const int iLen);
	





private:  

	/*<! ���*/
	int m_iID;

	/*<! ����*/
	ItemType m_eType;

	
	/*<! ����*/
	char m_Name[MAX_NAME_SIZE];
	/*<! ���ֳ���*/
	int m_iNameLen;
		
	/*<! ����*/
	char m_Description[MAX_DESCRIPTION_SIZE];
	/*<! ��������*/
	int m_iDescriptionLen;
	

};

#endif //__ITEMDATA_H__
