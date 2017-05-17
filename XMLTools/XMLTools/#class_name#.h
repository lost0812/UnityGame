
#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <string>

using std::string;

/**
 * @brief 怪物
 */
class Monster : 
{
public:
    Monster();
    ~Monster();
public:
		/**
		 * @brief 空对象
		 */
    static const Monster sGetNoMonster();
public:
	/**
	 * @brief 怪物类型
	 */
	enum MosterType
  {
        /*<! 温和*/
        MONSTER_TYPE_GENTLE = 0,
        /*<! 中立*/
        MONSTER_TYPE_NEUTRAL = 1,
        /*<! 敌对*/
        MOSTER_TYPE_HOSTIL = 2
  };

public:
    /**
		 * @brief 初始化
		 */
    virtual bool Init();
    
    /**
		 * @brief 初始化
		 */
    virtual bool Init(const Monster &monster);
    
    /**
		 * @brief 初始化
		 */
    virtual bool Init(const Monster::MonsterType eType,const string iDescription,const vector<int>& vDrop);

    /**
		 * @brief 字符串化
		 */
    virtual string ToString()const;
    /**
		 * @brief 反字符串化
		 */
    virtual bool FromString(const string sBuffer);

public:    
    /**
		 * @brief 获取怪物类型
		 */
    inline const Monster::MonsterType GetType() const{return m_eType;}
    /**
		 * @brief 获取描述
		 */
    inline const string GetDescription() const{return m_iDescription;}
    /**
		 * @brief 获取掉落
		 */
    inline const vector<int>& GetDrop() const{return m_vDrop;}

    /**
		 * @brief 设置怪物类型
		 */
    inline void SetType(const Monster::MonsterType eType){m_eType = eType;}
    /**
		 * @brief 设置描述
		 */
    inline void SetDescription(const string iDescription){m_iDescription = iDescription;}
    /**
		 * @brief 设置掉落
		 */
    inline void SetDrop(const vector<int>& vDrop){m_vDrop = vDrop;}

private:  
    /*<! 怪物类型*/
    Monster::MonsterType m_eType;
    /*<! 描述*/
    string m_iDescription;
    /*<! 掉落*/
    vector<int>& m_vDrop;
  
};  
  
#endif //__MONSTER_H__
