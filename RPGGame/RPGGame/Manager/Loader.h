#ifndef __LOADER_H__
#define __LOADER_H__

#include <map>
#include <string>
#include <google/protobuf/message.h>

using std::string;
using std::map;
using std::make_pair;

/**
 * @brief ������
 */
class Loader
{
public:
    Loader();
    virtual ~Loader();
public:
    /**
     * @brief ��ʼ��
     */
    virtual bool Init(const string sFile);
    /**
     * @brief ���������ļ�
     */
    virtual bool Load() = 0;
public:
    /**
     * @brief ��ȡ�����ļ�ȫ������
     */
    bool GetConfigArray( google::protobuf::Message &oProtobuf);
private:
    /*!< �����ļ� */
    string m_sFile;
};



#endif // __LOADER_H__

