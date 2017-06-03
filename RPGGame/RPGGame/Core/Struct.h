
#ifndef __STRUCT__H__
#define __STRUCT__H__



#include <vector>
#include <string>

#include "Cmd.h"

using std::vector;
using std::string;


/*!< ����߿� */
#define FrameCorner     "+"

/*!< ����߿� */
#define FrameHorizontal "-"

/*!< ����߿� */
#define FrameVertical   "|"



/*!< ��ͷͼ�� */
#define OptionArrow      "->"

/*!< �����ͷ */
#define OptionClearArrow "  "

/*!< ��ͷ��϶ */
#define OptionArrowGap 3


/*!< �޴��� */
#define NO_HANDLER 0

namespace data
{
	//-ö�ٽṹ----------------------------------------------------//
	/**
	 * @brief ����ö��
	 */
	enum Direction
	{
		/*!< ���� */
		DIRECTION_HORIZONTAL = 0,

		/*!< ���� */
		DIRECTION_VERTICAL = 1,

		/*!< ��� */
		DIRECTION_LEFT = 2,

		/*!< �ұ� */
		DIRECTION_RIGHT = 3,

		/*!< �ϱ� */
		DIRECTION_UP = 4,

		/*!< �±� */
		DIRECTION_DOWN = 5,

		/*!< ���� */
		DIRECTION_TOP = 6,

		/*!< �׶� */
		DIRECTION_BOTTOM = 7
	};

	/**
	* @brief ������
	*/
	enum FrameType
	{
		/*!< ��ͨ���� */
		FRAME_TYPE_NORMAL = 0,

		/*!< �������� */
		FRAME_TYPE_BAG = 1,

        /*!< ��Ʒ���� */
        FRAME_TYPE_ITEM = 2,

        /*!< �̵����� */
        FRAME_TYPE_SHOP = 3,

        /*!< �̵���Ʒ���� */
        FRAME_TYPE_SHOP_ITEM = 4,
	};

    /**
     * @brief ��״̬
     */
    enum FrameState
    {
        FRAME_STATE_NORMAL = 0,
        FRAME_STATE_FINISH = 1,
    };

	//-�򵥽ṹ----------------------------------------------------//
	/**
	 * @brief λ��
	 */
	struct Position
	{
		/*!< ������ */
		int iX;

		/*!< ������ */
		int iY;
	};

	/**
	 * @brief ��С
	 */
	struct Size
	{
		/*!< ��� */
		int iWidth;

		/*!< �߶� */
		int iHeigth;
	};

	/**
	 * @brief ѡ��
	 */
	struct Option
	{
		/*!< �������� */
		string sDescription;

		/*!< �������� */
		cmd::NotifyCommand eNotify;

		/*!< ѡ�к��Ӧ��ı�� */
        int iFrameID;

        /*!< ���ݱ�� */
        int iData;
	};

	


	//-���ݽṹ----------------------------------------------------//
	/**
	 * @brief ������
	 */
	struct FrameData
	{
		/*!< ��� */
		int iID;

		/*!< ���� */
		FrameType eType;

        /*!< ״̬ */
        FrameState eState;

		/*!< λ�� */
		Position oPosition;

		/*!< ��С */
		Size oSize;

		/*!< �������� */
		string sDescription;

		/*!< ѡ��� */
		Direction eDirection;

		/*!< ������ */
		int iHandlerID;

        /*!< ���ݱ�� */
        int iData;

        /*!< ѡ��ѡ�� */
        int iIndex;

        /*!< ѡ������ */
		vector<Option> vOptions;
	};

    /**
     * @brief ������Ԫ������
     */
    struct ContainerUnitData
    {
        /*!< ��� */
        int iID;

        /*!< ��Ʒ��� */
        int iItemID;

        /*!< ��Ʒ���� */
        int iItemNum;

        /*!< ��Ʒ������ */
        int iUnitCapacity;
    };

    /**
     * @brief ��������
     */
    struct ContainerData
    {
        /*!< ��� */
        int iID;

        /*!< ���� */
        int iCapacity;
    };

    /**
     * @brief ��Ʒ����
     */
    struct GoodsData
    {
        /*!< ��Ʒ��� */
        int iID;

        /*!< ��Ʒ��� */
        int iItemID;
        
        /*!< ���ι������� */
        int iAmount;
        
        /*!< ���ι���۸� */
        int iPrice;
    };
};


#define SET_GET(type,abbr_type,name,field)\
inline const type Get##name( )const\
{\
	return field;\
}\
inline void Set##name( const type abbr_type##name )\
{\
	field = abbr_type##name;\
}



#endif
