#include "franz.h"

Franz::Franz(std::string franzType, std::string franzName, int life, int mana, int armor, int XPGiven, int goldGiven) : Monster(franzType, franzName, life, mana, armor, XPGiven, goldGiven)
{
}

Franz::~Franz()
{
}

std::string Franz::getMonsterType() const
{
	return this->monsterType;
}

void Franz::receiveDamages(int damages)
{
	Monster::receiveDamages(damages);
	std::cout << "Il reste " << this->getLife() << " points de vie à " << this->getMonsterType() << " " << this->getMonsterName() <<"." << std::endl;
}

void Franz::attack(Entity & cible, int damages)
{
	cible.receiveDamages(damages);
}