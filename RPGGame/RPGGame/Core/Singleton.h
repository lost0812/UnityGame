#ifndef __SINGLETON_H__
#define __SINGLETON_H__


/**
* @brief �������ģʽ
*/
template<class T>
class Singleton
{
public:
	/**
	* @brief ��ȡʵ��
	*/
	inline static T& GetInstance()
	{
		static T t;
		return t;
	}
};



#endif // __SINGLETON_H__
