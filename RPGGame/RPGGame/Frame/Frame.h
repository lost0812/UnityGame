#ifndef __FRAME_H__
#define __FRAME_H__

#include "FrameConfigLoader.h"
#include "FrameData.h"

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

public:
    /**
     * @brief չʾ��
     */
    void Show()const;

protected:
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
    inline FrameConfig &UseFrameConfig() { return m_stConfig; }
    inline FrameData &UseFrameData() { return m_stData; }

    inline const FrameConfig &GetFrameConfig() const { return m_stConfig; }
    inline const FrameData &GetFrameData() const { return m_stData; }

    inline void SetFrameConfig(const FrameConfig &stFrameConfig) { m_stConfig = stFrameConfig; }
    inline void SetFrameData(const FrameData &stFrameData) { m_stData = stFrameData; }
private:
    /*!< ������ */
    FrameConfig m_stConfig;

    /*!< ������ */
    FrameData m_stData;
};

#endif // __FRAME_H__



