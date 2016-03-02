#include "Monster.h"

using namespace std;

Monster::Monster(std::string monsterType, std::string monsterName, int life, int mana, int armor, int XPGiven, int goldGiven) : 
monsterType(monsterType), monsterName(monsterName), Entity(life, mana, armor), experienceGiven(XPGiven), goldGiven(goldGiven)
{

}

Monster::~Monster()
{

}

string Monster::getMonsterType() const
{
    return this->monsterType;
}

void Monster::receiveDamages(int damages)
{
	Entity::receiveDamages(damages);
}

bool Monster::isAlive()
{
	int actualLife = this->getLife();
	if (actualLife <= 0)
	{
		this->setLife(0);
		this->alive = false;
		return this->alive;
	}
	else
	{
		this->alive = true;
		return this->alive;
	}

}
