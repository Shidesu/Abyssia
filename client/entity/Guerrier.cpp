#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier(int life, int mana, float armor, int level, int experience) : Personnage::Personnage(life, mana, armor, level, experience)
{

}

void Guerrier::dispPersoType() const
{
	std::cout << "Je suis un guerrier !" << endl;
}

void Guerrier::receiveDamages(float &damages)
{
		
	damages = damages * pow(0.99, this->getArmor());

    Personnage::receiveDamages(damages);
}

float Guerrier::getArmor() const
{
	return this->m_armor;
}

void Guerrier::setArmor(float newArmorValue)
{
	this->m_armor = newArmorValue;
}

void Guerrier::attack(Entity & cible, float damages)
{
	cible.receiveDamages(damages);
}

