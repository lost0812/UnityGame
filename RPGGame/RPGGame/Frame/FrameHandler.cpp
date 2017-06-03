#include "FrameHandler.h"
#include "ArrowManager.h"
#include "Cmd.h"
#include "FrameLoader.h"


#include "PropertyFrame.h"
#include "TipsFrame.h"



FrameHandler::FrameHandler()
{

}

FrameHandler::~FrameHandler()
{

}

bool FrameHandler::Init(Config *pConfig)
{
	if (!FrameLoader::GetInstance().Init())
		return false;

	RegisterCmd(cmd::COMMAND_IDLE);
	RegisterCmd(cmd::COMMAND_START);

    RegisterNotify(cmd::NOTIFY_UPDATE_PROPERTY);
    RegisterNotify(cmd::NOTIFY_UPDATE_INFORMATION);


    //���Կ�
    PropertyFrame::GetInstance().Init();

    //��ʾ��
    TipsFrame::GetInstance().Init();

    m_vStackFrames.clear();
    m_vStackFrames.reserve(10);

	return true;
}

int FrameHandler::Start()
{
	int iRet = Hander::Start();
	if (iRet != 0)
		return iRet;
	//todo
	return 0;
}

int FrameHandler::Stop()
{
	int iRet = Hander::Stop();
	if (iRet != 0)
		return iRet;
	//todo
	return 0;
}

void FrameHandler::Finish()
{

}

int FrameHandler::HandleIdle(req::Req &oReq)
{
	return 1;
}

int FrameHandler::HandleStart(req::Req &oReq)
{
    bool bIsRuning = true;
    //���Կ�
    PropertyFrame::GetInstance().Show();

    //��ʾ��
    TipsFrame::GetInstance().Show();

    //ѡ���
    FrameLoader &oFrameLoader = FrameLoader::GetInstance();
    FrameWithOption *pFrame = oFrameLoader.CreateFrameByID(0);
    m_vStackFrames.push_back(pFrame);

	while (bIsRuning)
    {
		pFrame = m_vStackFrames.back();
        
        //�����������
        if (DoForword(pFrame) < 0 || pFrame->GetState()==data::FRAME_STATE_FINISH)
        {
            PopStackFrame();
            continue;
        }
		pFrame->Show();

        //ѡ��ѡ��
        int iIndex = pFrame->GetSelectIndex();
		
        
		if (iIndex < 0 )//Esc�˳�
		{
            PopStackFrame();
            continue;
		}
        else//Enterѡ��
        {
            data::Option  stOption;
            //��ȡѡ����Ϣ
            if (!pFrame->GetOptionByIndex(iIndex, stOption))
                continue;

            //֪ͨ����
            if (stOption.eNotify != cmd::NOTIFY_IDLE )
                DoNotify(stOption.eNotify, iIndex, pFrame->GetData());


            //����
            if (stOption.iFrameID == -2)
                PopStackFrame();

            //��ת����Ӻ�����
            if (stOption.iFrameID >= 0 && pFrame->GetID() != stOption.iFrameID)
                PushStackFrame(iIndex, stOption);
        }
	}

	return 0;
}

int FrameHandler::Handle(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp)
{
	switch (eCmd)
	{
	case cmd::COMMAND_START:
		return HandleStart(oReq);
		break;
	}
	return 0;
}

void FrameHandler::Handle(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify)
{
    switch (eNotify)
    {
    case cmd::NOTIFY_UPDATE_PROPERTY:
    {
        PropertyFrame &oPropertyFrame = PropertyFrame::GetInstance();
        if (oNotify.HasInt(notify::i_PropertyFrame_Hp))
            oPropertyFrame.SetHp(oNotify.GetInt(notify::i_PropertyFrame_Hp));
        if (oNotify.HasInt(notify::i_PropertyFrame_MaxHp))
            oPropertyFrame.SetMaxHp(oNotify.GetInt(notify::i_PropertyFrame_MaxHp));
        if (oNotify.HasInt(notify::i_PropertyFrame_Money))
            oPropertyFrame.SetMoney(oNotify.GetInt(notify::i_PropertyFrame_Money));
        if (oNotify.HasInt(notify::i_PropertyFrame_Level))
            oPropertyFrame.SetLevel(oNotify.GetInt(notify::i_PropertyFrame_Level));
        if (oNotify.HasInt(notify::i_PropertyFrame_Exp))
            oPropertyFrame.SetExp(oNotify.GetInt(notify::i_PropertyFrame_Exp));
        if (oNotify.HasInt(notify::i_PropertyFrame_TotalExp))
            oPropertyFrame.SetTotalExp(oNotify.GetInt(notify::i_PropertyFrame_TotalExp));
        if (oNotify.HasInt(notify::i_PropertyFrame_Bag))
            oPropertyFrame.SetBag(oNotify.GetInt(notify::i_PropertyFrame_Bag));
        if (oNotify.HasInt(notify::i_PropertyFrame_TotalBag))
            oPropertyFrame.SetTotalBag(oNotify.GetInt(notify::i_PropertyFrame_TotalBag));
        oPropertyFrame.Update();

        break;
    }
    case cmd::NOTIFY_UPDATE_INFORMATION:
        TipsFrame &oTipsFrame = TipsFrame::GetInstance();
        oTipsFrame.SetDescription(oNotify.GetString(notify::s_TipsFrame_Description));
        oTipsFrame.Show();
        break;
    }

}

int FrameHandler::DoForword(FrameWithOption *const pFrame)
{
    if (pFrame == NULL)
        return -1;

    if (!pFrame->GetHandler())
        return 0;

    req::Req oReq;
    rsp::Rsp oRsp;

    //��������;
    pFrame->PrepareReq(pFrame->GetIndex(), oReq);
    if (0 == Forword(static_cast<const cmd::Command>(pFrame->GetHandler()), oReq, oRsp))
    {
        pFrame->PrepareRsp(oRsp);
        return 0;
    }
    return -1;
}

void FrameHandler::DoNotify(const cmd::NotifyCommand eNotifyCommand, const int iIndex, const int iData)
{
    notify::Notify oNotify;
    oNotify.Add(notify::i_Index, iIndex);
    oNotify.Add(notify::i_Data, iData);
    Notify(eNotifyCommand, oNotify);
}

void FrameHandler::PushStackFrame(const int iIndex, const data::Option &stOption )
{
    FrameWithOption *const pFrame = FrameLoader::GetInstance().CreateFrameByID(stOption.iFrameID);
    if (pFrame != NULL)
    {
        pFrame->SetData(stOption.iData);
        pFrame->SetIndex(iIndex);
        m_vStackFrames.push_back(pFrame);
    }
}

void FrameHandler::PopStackFrame()
{
    if (m_vStackFrames.size() > 1)
    {
        FrameLoader::GetInstance().ReleaseFrame(m_vStackFrames.back());
        m_vStackFrames.pop_back();
    }
}