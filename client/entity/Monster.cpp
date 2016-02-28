#include "Monster.h"

using namespace std;

Monster::Monster(std::string monsterType, std::string monsterName, int life, int mana, float armor, int XPGiven, int goldGiven) : 
m_monsterType(monsterType), m_monsterName(monsterName), Entity(life, mana, armor), m_experienceGiven(XPGiven), m_goldGiven(goldGiven)
{

}

Monster::~Monster()
{

}

string Monster::getMonsterType() const
{
    return this->m_monsterType;
}

void Monster::receiveDamages(float & damages)
{
	this->m_life = this->m_life - damages;
	if (this->m_life <= 0)
	{
		this->setLife(0);
		this->m_alive = false;
	}
	std::cout << "Il reste " << this->getLife() << " points de vie a " << getMonsterType() << std::endl;
}

float Monster::getArmor() const
{
	return this->m_armor;
}

int Monster::getLife() const
{
	return this->m_life;
}

void Monster::setLife(int lifeQuantity)
{
	this->m_life = lifeQuantity;
}

bool Monster::isAlive()
{
	int actualLife = this->getLife();
	if (actualLife <= 0)
	{
		this->setLife(0);
		this->m_alive = false;
		return this->m_alive;
	}
	else
	{
		this->m_alive = true;
		return this->m_alive;
	}

}
