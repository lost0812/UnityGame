#ifndef __TIPSFRAME_H__
#define __TIPSFRAME_H__

#include "Frame.h"
#include "Singleton.h"

/**
* @brief ��������ʾ����
*/
class TipsFrame : public Frame, public Singleton<TipsFrame>
{
public:
    TipsFrame();
    ~TipsFrame();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init(const FrameConfig &stConfig);
};



#endif // __TIPSFRAME_H__
