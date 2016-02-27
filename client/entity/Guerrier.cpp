#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier(int life, int mana, float armor, int level, int experience) : Personnage::Personnage(life, mana, level, experience), m_armor(armor)
{

}

void Guerrier::dispPersoType() const
{
    std::cout << "Je suis un guerrier !";
}

void Guerrier::receiveDamages(float &damages)
{
	damages = damages * pow(0.99, this->m_armor);
    Personnage::receiveDamages(damages);
}

