#include "franz.h"

Franz::Franz(std::string franzType, std::string franzName, int life, int mana, float armor, int XPGiven, int goldGiven) : Monster(franzType, franzName)
{
}

Franz::~Franz()
{
}

std::string Franz::getMonsterType() const
{
	return this->m_monsterType;
}
