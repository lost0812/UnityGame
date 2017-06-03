#ifndef __FRAMEWITHOPTION_H__
#define __FRAMEWITHOPTION_H__


#include <conio.h>

#include "Frame.h"
#include "Req.h"
#include "Rsp.h"




/**
* @brief ����
*/
class FrameWithOption : public Frame
{
public:
	FrameWithOption(void);
	~FrameWithOption(void);
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init( const data::FrameData &oFrameData );

	/**
	* @brief ������������
	*/
	virtual void PrepareReq(const int iIndex, req::Req &oReq);

	/**
	 * @brief ������Ӧ����
	 */
	virtual void PrepareRsp(const rsp::Rsp &oRsp);

public:
	/**
	* @brief ��ȡ��һ��ѡ��λ��
	*/
	bool GetArrawDefaultPosition(data::Position &stPosition) const;

	/**
	* @brief չʾ��
	*/
	void Show()const;

    /**
     * @brief ��ȡѡ��
     */
    int GetSelectIndex();

    /**
     * @brief ��ȡѡ��
     */
    bool GetOptionByIndex(unsigned int iIndex, data::Option &stOption)const;
private:
    /**
     * @brief �����
     */
    virtual void ClearFrame() const;

    /**
     * @brief ��������
     */
    virtual void ClearContent() const;

    /**
     * @brief չʾ��
     */
    virtual void ShowFrame() const;

    /**
    * @brief չʾ����
    */
    virtual void ShowDescription() const;

    /**
     * @brief չʾѡ��
     */
    virtual void ShowOptions() const;

public:
    /**
    * @brief ���ر���Ӧ��
    */
    bool CheckRsp(const rsp::Rsp &oRsp);
public:
	SET_GET(int,                   i, ID,          m_oFrameData.iID)
	SET_GET(data::FrameType,       e, Type,        m_oFrameData.eType)
    SET_GET(data::FrameState,      e, State,       m_oFrameData.eState)
	SET_GET(data::Position&,       o, Position,    m_oFrameData.oPosition)
	SET_GET(data::Size&,           o, Size,        m_oFrameData.oSize)
	SET_GET(string,                s, Description, m_oFrameData.sDescription)
	SET_GET(data::Direction,       e, Direction,   m_oFrameData.eDirection)
	SET_GET(int,                   i, Handler,     m_oFrameData.iHandlerID)
    SET_GET(int,                   i, Data,        m_oFrameData.iData)
    SET_GET(int,                   i, Index,       m_oFrameData.iIndex)
	SET_GET(vector<data::Option>&, v, Options,     m_oFrameData.vOptions)
private:
    /*!< ������ */
	data::FrameData m_oFrameData;
};



#endif // __FRAMEWITHOPTION_H__
