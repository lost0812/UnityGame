#ifndef __HOMEHANDLER_H__
#define __HOMEHANDLER_H__

#include "Singleton.h"
#include "Cmd.h"
#include "Req.h"
#include "Rsp.h"
#include "Notify.h"

class HomeHandler:public Singleton<HomeHandler>
{
public:
    HomeHandler();
    virtual ~HomeHandler();

public:
    /**
    * @brief չʾ�ֿ�
    */
    int HandleShowStorage(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief չʾ�ֿ���Ʒ
    */
    int HandleShowStorageItem(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief չʾ����
    */
    int HandleShowBag(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief չʾ������Ʒ
    */
    int HandleShowBagItem(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

public:
    /**
    * @brief ȡ���ֿ�
    */
    void HandleStorageTakeOut(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);

    /**
    * @brief ��Ųֿ�
    */
    void HandleStorageDeposit(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);
};




#endif // __HOMEHANDLER_H__

