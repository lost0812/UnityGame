#ifndef __PARSEXML_H__
#define __PARSEXML_H__

#include <string>
#include <map>
#include <vector>

using namespace std;

#include "tinyxml2.h"

using namespace tinyxml2;

/**
 * @brief ����xml
 */

class ParseXML
{
public:
    ParseXML();
    ~ParseXML();

public:
    /**
     * @brief ��������
     */
    struct Data
    {
        /*!< �ڵ����� */
        string node;

        string name;

        /*!< �ڵ����� */
        string parent;

        /*!< �ڵ����� */
        map<string, string> mapClassAttr;


        /*!< ��Ա���� */
        vector<map<string, string>> vecPropertyAttr;

		/*!< ��Ƕ���� */
        vector<Data> vecInner;

		/*!< ��Ƕ���� */
		vector<Data> vecProperty;
		/*!< ��Ƕ���� */
		vector<Data> vecClass;
		/*!< ��Ƕ���� */
		vector<Data> vecEnum;
		/*!< ��Ƕ���� */
		vector<Data> vecStruct;
    };
public:
    /**
     * @brief ����xml
     */
    bool Parse(const string sFileName);

    /**
     * @brief ����
     */
    void Clear();

    /**
     * @brief ��ȡ����
     */
    const vector<Data>& GetData()const;


private:
    /**
     * @brief ����xml
     */
    bool Parse(const XMLElement *cpXmlElement, Data &stData);
   
    /**
     * @brief ������
     */
    bool ParseClass(const XMLElement *cpXmlElement, Data &stData);
    
    /**
     * @brief �����ṹ��
     */
    bool ParseStruct(const XMLElement *cpXmlElement, Data &stData);
    
    /**
     * @brief ����ö��
     */
    bool ParseEnum(const XMLElement *cpXmlElement, Data &stData);

    /**
     * @brief ������Ա
     */
    bool ParseProperty(const XMLElement *cpXmlElement, Data &stData);

    /**
     * @brief ��������
     */
    bool ParseAttribute(const XMLElement *cpXmlElement, map<string,string> &mapAttr);


private:
    /*!< �ļ��� */
    string m_sFileName;

    /*!< �������� */
    vector<Data> m_vecData;
};

#endif // __PARSEXML_H__

