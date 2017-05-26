#ifndef __PARSEDATA_H__
#define __PARSEDATA_H__

#include <string>
#include <map>
#include <vector>

using namespace std;

#include "tinyxml2.h"

using namespace tinyxml2;

class ParseData
{
public:
    /**
     * @brief ���ݽṹ��
     */
    struct Data
    {
        /*!< �ڵ����� */
        string node;

        /*!< �ڵ����� */
        map<string, string> mapAttr;

        /*!< ���� */
        map<string, vector<Data>> mapChildren;
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
    * @brief ��������
    */
    bool ParseAttribute(const XMLElement *cpXmlElement, Data &stData);
private:

    /*!< �ļ��� */
    string m_sFileName;

    /*!< �������� */
    vector<Data> m_vecData;
};

#endif

