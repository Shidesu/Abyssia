#include "Personnage.h"
/* Les fonctions ci-dessous sont des esquisses de fonctions, et donc très loin d'être définitives.*/

Personnage::Personnage(int life, int mana) : m_life(life), m_mana(mana)
{
}

bool Personnage::isAlive()
{
	int actualLife = this->getLife();
		if (actualLife <= 0)
		{
			setLife(0);
			return false;
		}
		else
		{
			return true;
		}

}

void Personnage::receiveDamages(int damages)
{

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
