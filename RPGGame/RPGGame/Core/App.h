#ifndef __RPGAPP_H__
#define __RPGAPP_H__

#include <map>

using std::multimap;
using std::pair;

#include "Cmd.h"
#include "Singleton.h"
#include "FrameHandler.h"
#include "ManagerHandler.h"


/*!< ��ʵ�� */
#define g_FrameHandler FrameHandler::GetInstance()

/*!< Ӧ��ʵ�� */
#define g_App App::GetInstance()

/**
* @brief Ӧ���࣬�����������ģ��
*/
class App : public Singleton<App>
{
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init();
	/**
	* @brief ����Ӧ�÷���
	*/
	virtual int Start();
	/**
	* @brief ֹͣӦ�÷���
	*/
	virtual int Stop();
	/**
	* @brief ����Ӧ�÷���
	*/
	virtual void Finish();

public:
	/**
	* @brief �������Ĵ�����
	*/
	int AddCmdHandle(cmd::Command eCmd, Hander& oManager);

	/**
	* @brief �Ƴ�����Ĵ�����
	*/
	int RemoveCmdHandle(cmd::Command eCmd, Hander& oManager);

	/**
	* @brief ��������
	*/
	int Handler(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief ���֪ͨ�Ĵ�����
    */
    int AddNotifyHandle(cmd::NotifyCommand eNotify, Hander& oManager);

    /**
    * @brief �Ƴ�֪ͨ�Ĵ�����
    */
    int RemoveNotifyHandle(cmd::NotifyCommand eNotify, Hander& oManager);

    /**
    * @brief ����֪ͨ
    */
    void Notify(cmd::NotifyCommand eNotify, const notify::Notify &oNotify);
private:
	typedef multimap <cmd::Command, Hander&>::const_iterator CommandMMapIt;
	/*!< ����ʹ�������ӳ���ϵ */
    multimap<cmd::Command, Hander&> m_mmapCmdToHanders;

    typedef multimap <cmd::NotifyCommand, Hander&>::const_iterator NotifyMMapIt;
    /*!< ֪ͨ�ʹ�������ӳ���ϵ */
    multimap<cmd::NotifyCommand, Hander&> m_mmapNotifyToHanders;

	/*!< �Ƿ����� */
	bool m_bIsRuning;
};




#endif // __RPGAPP_H__
