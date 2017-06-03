#ifndef __HANDER_H__
#define __HANDER_H__

#include "Config.h"
#include "Cmd.h"
#include "Req.h"
#include "Rsp.h"
#include "Notify.h"


class App;
/**
* @brief ������
*/
class Hander
{
public:
	Hander();
	virtual ~Hander();
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init(Config *pConfig);
	/**
	* @brief ����ģ��
	*/
	virtual int Start();
	/**
	* @brief ֹͣģ��
	*/
	virtual int Stop();
	/**
	* @brief �ͷ�ģ��
	*/
	virtual void Finish();
public:
    /**
    * @brief ת�����͵�����
    */
    int Forword(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief ת�����͵�֪ͨ
    */
    void Notify(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);
public:
	/**
	* @brief ·�����������
	*/
	virtual int Handle(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp) = 0;

    /**
    * @brief ·��֪ͨ��������
    */
    virtual void Handle(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify) = 0;
protected:
	/**
	* @brief ע���������
	*/
	void RegisterCmd(const cmd::Command eCmd);

	/**
	* @brief ע���������
	*/
	void UnRegisterCmd(const cmd::Command eCmd);


    /**
    * @brief ע��֪ͨ������
    */
    void RegisterNotify(const cmd::NotifyCommand eNotify);

    /**
    * @brief ע��֪ͨ������
    */
    void UnRegisterNotify(const cmd::NotifyCommand eNotify);
};


#endif // __HANDER_H__

