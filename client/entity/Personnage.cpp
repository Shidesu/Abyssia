#include "Personnage.h"
/* Les fonctions ci-dessous sont des esquisses de fonctions, et donc très loin d'être définitives.*/

Personnage::Personnage(int life, int mana, float armor, int level, int experience, bool alive) : Entity(life, mana, armor, alive), m_level(level), m_experience(experience)
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
			this->m_alive = false;
			return this->m_alive;
		}
		else
		{
			this->m_alive = true;
			return this->m_alive;
		}

}

void Personnage::receiveDamages(float damages)
{
	Entity::receiveDamages(damages);
    std::cout << "Il vous reste " << this->getLife() << " points de vie." << std::endl;
}

int Personnage::getXP() const
{
	return this->m_experience;
}

void Personnage::setXP(int XPQuantity)
{
	this->m_experience = XPQuantity;
}


void Personnage::dispPersoType() const
{
}
