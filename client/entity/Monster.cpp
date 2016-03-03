#include "Monster.h"

using namespace std;

Monster::Monster(std::string monsterType, std::string monsterName, int life, int mana, int armor, int resistance, int XPGiven, int goldGiven) : 
monsterType(monsterType), monsterName(monsterName), Entity(life, mana, armor, resistance), experienceGiven(XPGiven), goldGiven(goldGiven)
{

}

Monster::~Monster()
{

}

string Monster::getMonsterName() const
{
	return this->monsterName;
}

string Monster::getMonsterType() const
{
    return this->monsterType;
}

void Monster::receiveDamages(Damages damages)
{
	Entity::receiveDamages(damages);
	std::cout << "Il reste " << this->getLife() << " points de vie � " << this->getMonsterType() << " " << this->getMonsterName() << "." << std::endl;
}

bool Monster::isAlive()
{
	int actualLife = this->getLife();
	if (actualLife <= 0)
	{
		this->setLife(0);
		this->alive = false;
		cout << "Vous avez tu� " << this->getMonsterType() << " " << this->getMonsterName() << " !!!" << endl;
		cout << "Vous gagnez " << this->experienceGiven << " exp�rience et " << this->goldGiven << " pi�ces d'or !" << endl << "Bien jou� ;)" << endl;
		return this->alive;
	}
	else
	{
		this->alive = true;
		return this->alive;
	}

}
