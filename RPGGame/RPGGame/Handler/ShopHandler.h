#ifndef __SHOPHANDLER_H__
#define __SHOPHANDLER_H__


#include "Singleton.h"
#include "Cmd.h"
#include "Req.h"
#include "Rsp.h"
#include "Notify.h"

class ShopHandler:public Singleton<ShopHandler>
{
public:
    ShopHandler();
    ~ShopHandler();
public:
    /**
    * @brief չʾ�̵�
    */
    int HandleShowShop(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief չʾ��Ʒ
    */
    int HandleShowShopItem(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

public:
        /**
    * @brief ����Ʒ
    */
    void HandleBuyShopItem(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);

    /**
    * @brief ����Ʒ
    */
    void HandleSellShopItem(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);
};


#endif // __SHOPHANDLER_H__
