#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include "Singleton.h"
#include "Manager.h"
#include "Player.h"
#include "Bag.h"
/**
* @brief ��ҹ���
*/
class PlayerManager:public Singleton<PlayerManager>,public Manager
{
public:
	PlayerManager();
	~PlayerManager();
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init();

    /**
     * @brief ����
     */
    virtual bool Save(const string sFile);

    /**
     * @brief ����
     */
    virtual bool Load(const string sFile);
public:

	/**
	* @brief ��ȡ����
	*/
	const Bag &GetBag();

    /**
    * @brief ��ӵ�����
    */
    bool AddToBag( const int iItemID, const int iNum);

    /**
     * @brief �ӱ���ȡ��
     */
    bool ReduceFromBag(const int iItemID, const int iNum);

     /**
      * @brief ����
      */
    bool Buy(const int iItemID, const int iPrice);

    /**
    * @brief ������
    */
    bool Sell(const int iItemID, const int iPrice);


    /**
     * @brief ����
     */
    void Attack(Actor &oActor);
    /**
     * @brief ��ȡ���
     */
    const Player & GetPlayer();
private:
    /*!< ���� */
    Bag m_oBag;

	/*!< ��� */
	Player m_oPlayer;
};

#endif // __PLAYERMANAGER_H__
