#ifndef __SHOWFRAME_H__
#define __SHOWFRAME_H__

#include "FrameWithOption.h"

/**
 * @brief �̵����
 */
class ShopFrame :public FrameWithOption
{
public:
    /**
    * @brief ������������
    */
    virtual void PrepareReq(const int iIndex, req::Req &oReq);

    /**
    * @brief ������Ӧ����
    */
    virtual void PrepareRsp(const rsp::Rsp &oRsp);
};


#endif // __SHOWFRAME_H__

