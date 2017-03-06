#pragma once

#include "Monster.h"
#include "../FightManagers/Damages.h"

class Franz : public Monster
{
public:
	Franz(std::string franzType = "Franz", std::string franzName = "", int life = 20, int mana = 10, int armor = 0, int resistance = 20, entityType unitType = entityType::Ennemy, int XPGiven = 5, int goldGiven = 10);
	virtual ~Franz();
	std::string getMonsterType() const;
	void attack(Entity & cible, int damages, Damages::DamagesType typeDegats);

protected:

};