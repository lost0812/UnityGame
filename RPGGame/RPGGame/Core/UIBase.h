#ifndef __UIBASE_H__
#define __UIBASE_H__

#include <windows.h>
#include <stdio.h>

/**
* @brief ������̨����ƶ�ָ��λ��
*/
void gotoxy(int x, int y);

/**
* @brief ����̨����ַ�
*/
void print(char c);

/**
* @brief ����ָ̨��λ������ַ�
*/
void print(int x, int y, char c);

/**
* @brief ����ָ̨��λ������ַ���
*/
void print(int x, int y, char *buffer);

/**
* @brief �������ָ̨��λ���ַ�
*/
void clearxy(int x, int y);

/**
* @brief �������ָ̨��λ��֮����ַ�
*/
void clearxy(int x1, int y1, int x2, int y2);

/**
* @brief �������̨�����ַ�
*/
void clear();

/**
* @brief ��ȡ����ָ̨��λ���ַ�
*/
void readxy(int x, int y, char &character);

/**
* @brief ���ÿ���̨��ɫ
*/
void setcolor(int fg,int bg);


#endif