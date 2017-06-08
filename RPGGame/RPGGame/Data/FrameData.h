
#ifndef __FRAMEDATA_H__
#define __FRAMEDATA_H__

#include <string>





using std::string;

/**
 * @brief ������
 */
class FrameData
{
public:

	/**
	 * @brief ��״̬
	 */
	enum FrameState
	{
		/*<! ����*/
		FRAME_STATE_NORMAL = 0,

		/*<! ����*/
		FRAME_STATE_FINISH = 0,

	};

public:
    FrameData();
    ~FrameData();
public:
    /**
     * @brief �ն���
     */
    static const FrameData &GetNoFrameData();
public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();
    
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const FrameData &oFrameData);
    
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
	 * @brief ��ȡ����
	 */
	inline const int &GetData() const{return m_iData;}

	/**
	 * @brief ��ȡѡ��ѡ��
	 */
	inline const int &GetIndex() const{return m_iIndex;}

	/**
	 * @brief ��ȡ��״̬
	 */
	inline const FrameData::FrameState &GetState() const{return m_eState;}


	/**
	 * @brief ʹ������
	 */
	inline int &UseData(){return m_iData;}

	/**
	 * @brief ʹ��ѡ��ѡ��
	 */
	inline int &UseIndex(){return m_iIndex;}

	/**
	 * @brief ʹ�ÿ�״̬
	 */
	inline FrameData::FrameState &UseState(){return m_eState;}

	
	/**
	 * @brief ��������
	 */
	inline void SetData(const int &iData){m_iData = iData;}
	
	/**
	 * @brief ����ѡ��ѡ��
	 */
	inline void SetIndex(const int &iIndex){m_iIndex = iIndex;}
	
	/**
	 * @brief ���ÿ�״̬
	 */
	inline void SetState(const FrameData::FrameState &eState){m_eState = eState;}







private:  

	/*<! ����*/
	int m_iData;

	/*<! ѡ��ѡ��*/
	int m_iIndex;

	/*<! ��״̬*/
	FrameData::FrameState m_eState;



};

#endif //__FRAMEDATA_H__
