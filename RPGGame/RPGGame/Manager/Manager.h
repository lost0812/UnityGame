#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <string>

using std::string;

class Manager
{
public:
    Manager();
    virtual ~Manager();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init() = 0;

    /**
    * @brief ����
    */
    virtual bool Save(const string sFile) = 0;

    /**
    * @brief ����
    */
    virtual bool Load(const string sFile) = 0;
};



#endif // __MANAGER_H__


