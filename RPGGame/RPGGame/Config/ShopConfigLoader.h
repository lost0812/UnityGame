
#ifndef __SHOPCONFIG_LOADER_H__
#define __SHOPCONFIG_LOADER_H__



#define g_ShopConfigLoader ShopConfigLoader::GetInstance()

#include <vector>
#include <string>

#include "Singleton.h"


using std::vector;
using std::string;



/**
 * @brief ����
 */
struct ShopConfig
{	
		/*!< ��� */
		int iID;
		
		/*!< ��Ʒ��� */
		int iItemID;
		
		/*!< ��Ʒ���� */
		int iItemNum;
		
		/*!< �۸� */
		int iPrice;
		
		/*!< ��Ʒ���� */
		int iDiscount;
	



};

class ShopConfigLoader : public Singleton<ShopConfigLoader>
{
public:
	/**
	 * @brief ��ʼ��
	 */
    bool Init();
	
public:
	/**
	 * @brief ��ȡȫ������
	 */
	const vector<ShopConfig> &GetAllConfig();
	
	/**
	 * @brief ͨ��������ȡ����
	 */
	const ShopConfig *GetShopConfigByIndex(const unsigned int uIndex);
	
	/**
	 * @brief ͨ����Ż�ȡ����
	 */
	const ShopConfig *GetShopConfigByID(const int iID);
		
	/**
	 * @brief ͨ����Ʒ��Ż�ȡ����
	 */
	const ShopConfig *GetShopConfigByItemID(const int iItemID);
		
	/**
	 * @brief ͨ����Ʒ������ȡ����
	 */
	const ShopConfig *GetShopConfigByItemNum(const int iItemNum);
		
	/**
	 * @brief ͨ���۸��ȡ����
	 */
	const ShopConfig *GetShopConfigByPrice(const int iPrice);
		
	/**
	 * @brief ͨ����Ʒ������ȡ����
	 */
	const ShopConfig *GetShopConfigByDiscount(const int iDiscount);
	

private:
	/*!< �������� */
    vector<ShopConfig> m_vecRecords;
};

#endif //__SHOPCONFIG_LOADER_H__
