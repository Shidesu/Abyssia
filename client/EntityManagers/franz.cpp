#include "franz.h"
#include <fstream>
#include <iostream>

Franz::Franz(std::string franzType, std::string franzName, int life, int mana, int armor, int resistance, entityType unitType, int XPGiven, int goldGiven) : Monster(franzType, franzName, life, mana, armor, resistance, unitType, XPGiven, goldGiven)
{
	json j;
	j["FranzType"] = franzType;
	j["Hit Points"] = life;
	std::ofstream fichier("franzT.json");
	if (fichier) {
		fichier << std::setw(4) << j << std::endl;
		fichier.close();
	}
	else {
		std::cout << "Erreur" << std::endl;
	}

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
	if (this->isAlive())
	{
		Damages damagesT(damages, this, typeDegats);
		//Damages damages(damages, this, Damages::DamagesType::Physical);
		cible.receiveDamages(damagesT);
		//je suis le test visual studio #git
	}
}