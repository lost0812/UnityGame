#ifndef __MANAGERHANDLER_H__
#define __MANAGERHANDLER_H__


#include "Cmd.h"
#include "Singleton.h"
#include "Hander.h"
#include "ItemLoader.h"

/*!< ��������ʵ�� */
#define g_ManagerHandler ManagerHandler::GetInstance()

/**
* @brief �������࣬��������Ż��ӿ�
*/
class ManagerHandler :public Singleton<ManagerHandler>,public Hander
{
public:
	ManagerHandler();
	~ManagerHandler();
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init(Config *pConfig);

    /**
    * @brief ����ģ��
    */
    virtual int Start();
public:
	/**
	* @brief �ַ��������������
	*/
	virtual int Handle(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief ·��֪ͨ��������
    */
    virtual void Handle(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);

public:
    /**
     * @brief ������Ϣ����ʾ��
     */
    void UpdateTipsFrame( const string sNotifyMessage );

    /**
     * @brief ������Ϣ�����Կ�
     */
    void UpdatePropertyFrame();

public:
    /**
    * @brief ���������������
    */
    bool CheckReqIndex(const int iIndexMax, const req::Req &oReq, rsp::Rsp &oRsp) const;

    /**
    * @brief ����������ݲ���
    */
    bool CheckReqData(const req::Req &oReq, rsp::Rsp &oRsp) const;

    /**
     * @brief ���֪ͨ���ݲ���
     */
    bool CheckNotifyData(const int iDataMax, const notify::Notify &oNotify) const;

    /**
     * @brief ������ѡ��
     */
    bool RspWithNoOption(const string sDescription, rsp::Rsp &oRsp);

};



#endif //__MANAGERHANDLER_H__