#ifndef __FRAMEHANDLER_H__
#define __FRAMEHANDLER_H__

#include <list>
#include <vector>

#include "Singleton.h"
#include "Hander.h"
#include "FrameWithOption.h"


using std::list;
using std::vector;
/**
* @brief ������
*/
class FrameHandler : public Singleton<FrameHandler>,public Hander
{
public:
	FrameHandler();
	virtual ~FrameHandler();
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
	 * @brief ������н���
	 */
	int HandleIdle(req::Req &oReq);

	/**
	 * @brief ����ʼ����
	 */
	int HandleStart(req::Req &oReq);
private:
	/**
	 * @brief ��������·��
	 */
	virtual int Handle(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
     * @brief ����֪ͨ·��
     */
    virtual void Handle(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);

private:
    /**
     * @brief ��������
     */
    int DoForword( FrameWithOption *const pFrame);

    /**
     * @brief ����֪ͨ
     */
    void DoNotify(const cmd::NotifyCommand eNotifyCommand, const int iIndex, const int iData);

    /**
     * @brief ����ջ
     */
    void PushStackFrame(const int iIndex, const data::Option &stOption);

    /**
     * @brief ���ջ
     */
    void PopStackFrame();

private:
	/*!< ��ʾ���ջ */
    vector<FrameWithOption*> m_vStackFrames;
};

#endif // __FRAMEHANDLER_H__
