#ifndef __BAGFRAME_H__
#define __BAGFRAME_H__


#include "FrameWithOption.h"

/**
* @brief ��������
*/
class BagFrame :public FrameWithOption
{
public:
	BagFrame();
	~BagFrame();
private:
	/**
	* @brief ������������
    */
    virtual void PrepareReq(const int iSelected, req::Req &oReq);

	/**
	* @brief ������Ӧ����
	*/
	virtual void PrepareRsp(const rsp::Rsp &oRsp);
};

#endif // __BAGFRAME_H__
