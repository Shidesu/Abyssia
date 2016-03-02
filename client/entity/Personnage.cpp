#include "Personnage.h"
/* Les fonctions ci-dessous sont des esquisses de fonctions, et donc très loin d'être définitives.*/

Personnage::Personnage(int life, int mana, int armor, int level, int experience, bool alive) : Entity(life, mana, armor, alive), level(level), experience(experience)
{
}

Personnage::~Personnage()
{

}

bool Personnage::isAlive()
{
	int actualLife = this->getLife();
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

void Personnage::receiveDamages(int damages)
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


void Personnage::dispPersoType() const
{
}
