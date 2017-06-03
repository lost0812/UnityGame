#ifndef __MANAGERINSTANCE_H__
#define __MANAGERINSTANCE_H__

#include "ManagerHandler.h"

#include "StrUtil.h"
#include "HomeManager.h"
#include "PlayerManager.h"
#include "ItemManager.h"
#include "ShopManager.h"
#include "MapManager.h"

/*!< ��ʵ�� */
#define g_HomeManager HomeManager::GetInstance()

/*!< ���ʵ�� */
#define g_PlayerManger PlayerManager::GetInstance()

/*!< ��Ʒʵ�� */
#define g_ItemManager  ItemManager::GetInstance()

/*!< �̵�ʵ�� */
#define g_ShopManager ShopManager::GetInstance()

#define g_MapManager MapManager::GetInstance()

#endif // __MANAGERINSTANCE_H__
