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

void Franz::attack(Entity & cible, int damages, Damages::DamagesType typeDegats)
{
	Damages damagesT(damages, this, typeDegats);
	//Damages damages(damages, this, Damages::DamagesType::Physical);
	cible.receiveDamages(damagesT);
}