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

        /*!< �ڵ����� */
        string name;

        /*!< �ڵ㸸�� */
        string parent;

        /*!< �ڵ����� */
        map<string, string> mapClassAttr;


		/*!< �������� */
        vector<Data> vecProperty;

        /*!< ������������ */
        vector<Data> vecArrayProperty;
		
        /*!< ������ */
        vector<Data> vecMacro;

        /*!< ȫ������ */
        vector<Data> vecGloble;

        /*!< �ڲ������� */
		vector<Data> vecClass;

		/*!< �ڲ�ö������ */
		vector<Data> vecEnum;

		/*!< �ڲ��ṹ������ */
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
    * @brief ���������Ա
    */
    bool ParseArrayProperty(const XMLElement *cpXmlElement, Data &stData);
    /**
    * @brief ������
    */
    bool ParseMacro(const XMLElement *cpXmlElement, Data &stData);
    /**
    * @brief ����ȫ��
    */
    bool ParseGloble(const XMLElement *cpXmlElement, Data &stData);

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

