#ifndef __FRAMELOADER_H__
#define __FRAMELOADER_H__

#include <map>

using std::map;
using std::pair;

#include "dataconfig_frame.pb.h"

#include "Platform.h"
#include "Singleton.h"
#include "Struct.h"
#include "FrameWithOption.h"
#include "BagFrame.h"
#include "ItemFrame.h"
#include "ShopFrame.h"
#include "ShopItemFrame.h"


#define FRAMEFIEL "proto/data/dataconfig_frame.data"

using dataconfig::FRAME;
using dataconfig::FRAMEArray;

using data::FrameType;
using data::Direction;

/**
* @brief �������
*/
class FrameLoader : public Singleton<FrameLoader>
{
public:
	/**
	* @brief ��ʼ��
	*/
	bool Init();
public:
	/**
	* @brief ��������ȡ��
	*/
	FrameWithOption *CreateFrameByID(int iID);

	/**
	* @brief �ͷſ�
	*/
	void ReleaseFrame(FrameWithOption *pFrame);
private:
	/**
	* @brief ������
	*/
	FrameWithOption *CreateFrameInstanceByType(const data::FrameType eType);
private:
	/*!< ������ӳ�� */
	map<int, data::FrameData> m_mapFrameDatas;
};




#endif // __FRAMELOADER_H__
