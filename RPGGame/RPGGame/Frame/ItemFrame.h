#ifndef __ITEMFRAME_H__
#define __ITEMFRAME_H__


#include "FrameWithOption.h"

/**
 * @brief ��Ʒ����
 */
class ItemFrame :public FrameWithOption
{
public:
	ItemFrame();
	~ItemFrame();
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


#endif // __ITEMFRAME_H__
