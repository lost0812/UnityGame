#include "MonsterLoader.h"

#include "dataconfig_monsterconfig.pb.h"
#include "Platform.h"

using dataconfig::MonsterConfigArray;
using dataconfig::MonsterConfig;

using platform::UTF_82ASCII;

MonsterLoader::MonsterLoader()
{
}


MonsterLoader::~MonsterLoader()
{
}

bool MonsterLoader::Load()
{
    MonsterConfigArray arrayMonster;
    if (!GetConfigArray(arrayMonster))
        return false;

    m_mapMonsters.clear();

    vector<int> vDrop;
    for (int i = 0; i < arrayMonster.items_size(); ++i)
    {
        vDrop.clear();

        const MonsterConfig &oConfig = arrayMonster.items(i);

        for (int j = 0; j < oConfig.dropid_size(); ++j)
            vDrop.push_back(oConfig.dropid(j));

        Monster oMonster;
        oMonster.Init(
            oConfig.id(),
            UTF_82ASCII(oConfig.name()),
            oConfig.maxhp(),
            oConfig.maxhp(),
            oConfig.attack(),
            oConfig.defance(),
            static_cast<Monster::MonsterType>(oConfig.type()),
            UTF_82ASCII(oConfig.description()),
            vDrop);

        m_mapMonsters.insert(make_pair(oMonster.GetID(), oMonster));
    }

    return true;
}

const Monster & MonsterLoader::GetMonsterByID(const int iID)const 
{
    map<int, Monster>::const_iterator it = m_mapMonsters.find(iID);

    if (it != m_mapMonsters.end())
        return it->second;

    return Monster::GetNoMonster();
}

int MonsterLoader::GetMonsterNum() const
{
    return m_mapMonsters.size();
}
