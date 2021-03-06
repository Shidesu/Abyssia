#include "Personnage.h"
/* Les fonctions ci-dessous sont des esquisses de fonctions, et donc tr�s loin d'�tre d�finitives.*/

Personnage::Personnage(int life, int mana, int armor, entityType unitType, int resistance, int level, int experience, bool alive) : Entity(life, mana, armor, resistance, unitType, ""), level(level), experience(experience)
{
}

Personnage::~Personnage()
{

}

void Personnage::attack(Entity & cible, int const& damages, Damages::DamagesType typeDegats)
{
	std::cout << "test";
}

bool Personnage::isAlive()
{
	int actualLife = getLife();
	if (actualLife <= 0)
	{
		this->setLife(0);
		std::cout << "Vous avez perdu..." << std::endl;
		this->alive = false;
		return this->alive;
	}
	else
	{
		this->alive = true;
		return this->alive;
	}

}

void Personnage::receiveDamages(Damages damages)
{
	Entity::receiveDamages(damages);
	std::cout << "Il vous reste " << this->getLife() << " points de vie." << std::endl;
}

int Personnage::getExperience() const
{
	return this->experience;
}

void Personnage::setExperience(int experience)
{
	this->experience = experience;
}


void Personnage::dispPersoType()
{
}
