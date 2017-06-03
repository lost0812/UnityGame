#ifndef __NOTIFY_H__
#define __NOTIFY_H__

#include <map>
#include <string>
#include <vector>

#include "Cmd.h"

using std::map;
using std::vector;
using std::string;
using std::pair;

/**
* @brief ֪ͨ�����ռ�
*/
namespace notify
{
    /** @brief Frame->Manager **/
    const string i_Index = "i_Index";
    const string i_Data = "i_Data";

    /** @brief Manager->PropertyFrame **/
    const string i_PropertyFrame_Hp = "i_PropertyFrame_Hp";
    const string i_PropertyFrame_MaxHp = "i_PropertyFrame_MaxHp";
    const string i_PropertyFrame_Money = "i_PropertyFrame_Money";
    const string i_PropertyFrame_Level = "i_PropertyFrame_Level";
    const string i_PropertyFrame_Exp = "i_PropertyFrame_Exp";
    const string i_PropertyFrame_TotalExp = "i_PropertyFrame_TotalExp";
    const string i_PropertyFrame_Bag = "i_PropertyFrame_Bag";
    const string i_PropertyFrame_TotalBag = "i_PropertyFrame_TotalBag";

    /** @brief Manager->TipsFrame **/
    const string s_TipsFrame_Description = "s_TipsFrame_Description";


    /**
     * @brief ֪ͨ��
     */
    class Notify
    {
    public:
        Notify();
        ~Notify();
    public:
        /**
        * @brief ��ʼ��
        */
        virtual bool Init(cmd::NotifyCommand eCmd);

        /**
        * @brief ��ȡָ��
        */
        cmd::NotifyCommand GetCmd();

        /**
        * @brief ������Ͳ���
        */
        void Add(const string sKey, const int iValue);

        /**
        * @brief ����ַ�������
        */
        void Add(const string sKey, const string sValue);

        /**
        * @brief ����������
        */
        void Add(const string sKey, const vector<Notify> vValue);

        /**
        * @brief ��ȡָ�����Ͳ���
        */
        const int GetInt(const string sKey)const;

        /**
        * @brief ��ȡָ���ַ�������
        */
        const string GetString(const string sKey)const;

        /**
        * @brief ��ȡָ���������
        */
        const vector<Notify> GetVector(const string sKey)const;

        /**
        * @brief �Ƿ���ָ�����Ͳ���
        */
        const bool HasInt(const string sKey)const;

        /**
        * @brief �Ƿ���ָ���ַ�������
        */
        const bool HasString(const string sKey)const;

        /**
        * @brief �Ƿ���ָ���������
        */
        const bool HasVector(const string sKey)const;
    private:
        /*!< ָ�� */
        cmd::NotifyCommand m_eNotifyCmd;
        /*!< ���Ͳ���ӳ�� */
        map<string, int> m_mapIntArg;
        /*!< �ַ�������ӳ�� */
        map<string, string> m_mapStringArg;
        /*!< �������ӳ�� */
        map<string, vector<Notify>> m_mapVectorArg;

    };
};

#endif // __NOTIFY_H__
