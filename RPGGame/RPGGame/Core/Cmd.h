#ifndef __CMD_H__
#define __CMD_H__

/**
* @brief ���������ռ�
*/
namespace cmd
{
	/**
	 * @brief ����ö��
	 */
    enum Command
    {
        /*!< �� */
        COMMAND_IDLE = 0,

        /*!< ��ʼ */
        COMMAND_START,

        /*!< չʾ���� */
        COMMAND_SHOW_BAG = 2100000,

        /*!< չʾ��Ʒ */
        COMMAND_SHOW_ITEM = 2110000,

        /*!< չʾ�̵� */
        COMMAND_SHOW_SHOP = 1200000,

        /*!< չʾ��Ʒ */
        COMMAND_SHOW_SHOP_ITEM = 1210000,

        /*!< չʾ�ֿ� */
        COMMAND_SHOW_STOGAE = 1121000,

        /*!< չʾ�ֿ���Ʒ */
        COMMAND_SHOW_STOGAE_ITEM = 1121100,

        /*!< �ڼ�չʾ���� */
        COMMAND_HOME_SHOW_BAG = 1122000,

        /*!< �ڼ�չʾ������Ʒ */
        COMMAND_HOME_SHOW_BAG_ITEM = 1122100,

        /*!< չʾ��ͼ */
        COMMAND_SHOW_MAP = 3000000,

        /*!< ��ͼ���� */
        COMMAND_SHOW_MAP_ACTION = 3100000,

        /*!< �������� */
        COMMAND_MEET_MONSTER = 3120000,

    };

    /**
    * @brief ֪ͨö��
    */
    enum NotifyCommand
    {
        /*!< �� */
        NOTIFY_IDLE = 0,
        /*!< �̵� */
        NOTIFY_SHOP_BUY = 1210001,
        NOTIFY_SHOP_SELL = 1210002,



        /*!< �ֿ� */
        NOTIFY_STORAGE_TAKEOUT = 1121101,
        NOTIFY_STORAGE_DEPOSIT = 1122101,

        /*!< Ұ�� */
        NOTIFY_MAP_ATTACK = 3110001,
        NOTIFY_MAP_RUN = 3110002,


        /*!< ���� */
        NOTIFY_UPDATE_PROPERTY = 20001,
        NOTIFY_UPDATE_INFORMATION = 20002,
    };
}



#endif // __CMD_H__

