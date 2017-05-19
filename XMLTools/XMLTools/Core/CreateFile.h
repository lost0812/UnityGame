#ifndef __CREATEFILE_H__
#define __CREATEFILE_H__
 
#include <stdarg.h>
 
#include "ParseXML.h"
 
 
/**
* @brief ����c++Դ�ļ�
*/
class CreateFile
{
public:
    CreateFile();
    ~CreateFile();

public:
    class TranslateClass
    {
	public:
		bool Translate2(
            const XMLElement *cpXmlElement, 
            const ParseXML::Data &stData,
            const map<string,string> &mapParent,
            map<string, string> &mapBase);
    private:
        bool ConvertParam(string &sValue, const char * csParam);
		bool TranslateAttr(const XMLElement *cpXmlElement, const map<string, string> &mapData, map<string, string> &mapBase);
		bool TranslateList(
			const XMLElement *cpXmlElement,
			const vector<ParseXML::Data> vecData,
            vector<map<string, string>> &vecBaseList);
        bool TranslateCompose2(const XMLElement *cpXmlElement, map<string, string> &mapBase);
        bool TranslateParent(const XMLElement *cpXmlElement, map<string, string> &mapBase);
    private:
        //��������
        map<string, string> m_mapBase;
        map<string, string> m_mapParent;

        vector<map<string, string>> m_vecProperty;
        vector<map<string, string>> m_vecArrayProperty;
        vector<map<string, string>> m_vecMacro;
        vector<map<string, string>> m_vecGlobe;
		vector<map<string, string>> m_vecEnum;
		vector<map<string, string>> m_vecStruct;
		vector<map<string, string>> m_vecClass;
    };
public:
    /**
    * @brief ����Դ�ļ�
    */
    bool Create(
        const string sTemplateFile, 
        const ParseXML::Data &stData,
        const map<string, string> &mapParent = map<string, string>());
 
    /**
     * @brief ��ȡ��������
     */
    const map<string, string> &GetBase();
    const map<string, string> &GetFile();
private:
    /**
     * @brief ת���ļ�
     */
    bool TranslateFile(const XMLElement *cpXmlElement, map<string, string> &mapBase);

private:
    //��������
    map<string, string> m_mapBase;

    //�ļ�
    map<string, string> m_mapFile;
};
 
 
 
#endif // __CREATECPPFILE_H__
