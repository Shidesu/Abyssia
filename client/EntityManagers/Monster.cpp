#include "Monster.h"

using namespace std;

Monster::Monster(std::string monsterType, std::string monsterName, int life, int mana, int armor, int resistance, entityType unitType, int XPGiven, int goldGiven) : 
monsterType(monsterType), monsterName(monsterName), Entity(life, mana, armor, resistance,unitType, ""), experienceGiven(XPGiven), goldGiven(goldGiven)
{

}

Monster::~Monster()
{

}

string Monster::getMonsterName() const
{
	return monsterName;
}

string Monster::getMonsterType() const
{
    return monsterType;
}

void Monster::receiveDamages(Damages damages)
{
	Entity::receiveDamages(damages);
	std::cout << "Il reste " << getLife() << " points de vie � " << getMonsterType() << " " << getMonsterName() << "." << std::endl;
}

bool Monster::isAlive()
{
	int actualLife = getLife();
	if (actualLife <= 0)
	{
		setLife(0);
		alive = false;
		cout << "Vous avez tu� " << getMonsterType() << " " << getMonsterName() << " !!!" << endl;
		cout << "Vous gagnez " << experienceGiven << " exp�rience et " << goldGiven << " pi�ces d'or !" << endl << "Bien jou� ;)" << endl;
		return alive;
	}
	else
	{
		alive = true;
		return alive;
	}

}
