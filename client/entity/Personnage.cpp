#include "Personnage.h"
/* Les fonctions ci-dessous sont des esquisses de fonctions, et donc très loin d'être définitives.*/

Personnage::Personnage(int life, int mana, int level, int experience) : m_life(life), m_mana(mana), m_level(level), m_experience(experience), m_alive(true)
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

void Personnage::receiveDamages(int damages)
{
    this->m_life = this->m_life - damages;
    if(this->m_life <= 0)
    {
        this->setLife(0);
        this->m_alive = false;
    }
    std::cout << "Il vous reste " << this->getLife() << " points de vie." << std::endl;
}

int Personnage::getMana() const
{
	return this->m_mana;
}

void Personnage::setMana(int manaQuantity)
{
	this->m_mana = manaQuantity;
}

int Personnage::getLife() const
{
	return this->m_life;
}

void Personnage::setLife(int lifeQuantity)
{
	this->m_life = lifeQuantity;
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
