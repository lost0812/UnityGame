#ifndef __FRAME_H__
#define __FRAME_H__

#include "Struct.h"

class Frame
{
public:
    Frame();
    ~Frame();
public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init();

    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const data::FrameData &oFrameData);

public:
    /**
     * @brief չʾ��
     */
    void Show()const;
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
public:
    SET_GET(int,                   i, ID,          m_stFrameData.iID)
    SET_GET(data::FrameType,       e, Type,        m_stFrameData.eType)
    SET_GET(data::Position&,       o, Position,    m_stFrameData.oPosition)
    SET_GET(data::Size&,           o, Size,        m_stFrameData.oSize)
    SET_GET(string,                s, Description, m_stFrameData.sDescription)
    SET_GET(data::Direction,       e, Direction,   m_stFrameData.eDirection)
    SET_GET(int,                   i, Handler,     m_stFrameData.iHandlerID)
    SET_GET(int,                   i, Data,        m_stFrameData.iData)
    SET_GET(int,                   i, Index,       m_stFrameData.iIndex)
    SET_GET(vector<data::Option>&, v, Options,     m_stFrameData.vOptions)
private:
    /*!< ������ */
    data::FrameData m_stFrameData;
};

#endif // __FRAME_H__



