#ifndef __SHOPITEMFRAME_H__
#define __SHOPITEMFRAME_H__

#include "FrameWithOption.h"
/**
 * @brief ��Ʒ��
 */
class ShopItemFrame :public FrameWithOption
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

#endif // __SHOPITEMFRAME_H__

