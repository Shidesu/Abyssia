#include "Monster.h"

using namespace std;

Monster::Monster(std::string monsterType, std::string monsterName, int life, int mana, float armor, int XPGiven, int goldGiven) : 
m_monsterType(monsterType), m_monsterName(monsterName), m_life(life), m_mana(mana), m_armor(armor),m_experienceGiven(XPGiven), m_goldGiven(goldGiven)
{

}

Monster::~Monster()
{

}

string Monster::getMonsterType() const
{
    return this->m_monsterType;
}
