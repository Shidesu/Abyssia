#include "franz.h"

Franz::Franz(std::string franzType, std::string franzName, int life, int mana, float armor, int XPGiven, int goldGiven) : Monster(franzType, franzName, life, mana, armor, XPGiven, goldGiven)
{
}

Franz::~Franz()
{
}

std::string Franz::getMonsterType() const
{
	return this->m_monsterType;
}

void Franz::receiveDamages(float & damages)
{
	damages = damages * pow(0.99, this->getArmor());

	Monster::receiveDamages(damages);
}

void Franz::attack(Entity & cible, float damages)
{
	cible.receiveDamages(damages);
}