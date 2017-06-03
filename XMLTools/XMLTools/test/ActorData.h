
#ifndef __ACTORDATA_H__
#define __ACTORDATA_H__

#include <string>







using std::string;

/**
 * @brief �ж�������
 */
class ActorData 
{
public:
    ActorData();
    ~ActorData();
public:
    /**
     * @brief �ն���
     */
    static const ActorData &GetNoActorData();
public:


public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const ActorData &oActorData);
    
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
	 * @brief ��ȡ����ֵ
	 */
	inline const int GetHp() const{return m_iHp;}

	
	/**
	 * @brief ���ñ��
	 */
	inline void SetID(const int iID){m_iID = iID;}
	
	/**
	 * @brief ��������ֵ
	 */
	inline void SetHp(const int iHp){m_iHp = iHp;}








private:  

	/*<! ���*/
	int m_iID;

	/*<! ����ֵ*/
	int m_iHp;



};

#endif //__ACTORDATA_H__
