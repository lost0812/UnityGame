#include "ShopFrame.h"



void ShopFrame::PrepareReq(const int iIndex, req::Req &oReq)
{
    oReq.Init(cmd::COMMAND_SHOW_SHOP);

    oReq.Add(req::i_Index, iIndex);
}

void ShopFrame::PrepareRsp(const rsp::Rsp &oRsp)
{
    if (!CheckRsp(oRsp))
        return;

    vector<data::Option> vOptions;
    data::Option stOption;
    vector<rsp::Rsp> vRsp = oRsp.GetVector(rsp::v_ShopItem);
    for (vector<rsp::Rsp>::iterator it = vRsp.begin(); it != vRsp.end(); ++it)
    {
        char chDescription[128];
        sprintf(chDescription,
            "Item:%d,Num:%d,Price:%d",
            it->GetInt(rsp::i_ShopItem_ItemID),
            it->GetInt(rsp::i_ShopItem_Amount),
            it->GetInt(rsp::i_ShopItem_Price));
        stOption.sDescription = chDescription;
        stOption.iFrameID = 5;
        vOptions.push_back(stOption);
    }
    SetOptions(vOptions);
}
