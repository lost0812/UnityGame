#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>
using std::string;


/**
* @brief ������
*/
class Config
{
public:
	Config();
	~Config();
public:
	/**
	* @brief ���������ļ�
	*/
	void Load(string file_name);

	/**
	* @brief ���������ļ�
	*/
	void Save(string file_name = "");
public:
	/**
	* @brief ��ȡ������Ϣ
	*/
	string GetValue(string key);

	/**
	* @brief ����������Ϣ
	*/
	void SetValue(string key, string value);
private:

};



#endif // __CONFIG_H__
