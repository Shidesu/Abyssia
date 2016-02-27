#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier(int life, int mana, int level, int experience) : Personnage::Personnage(life, mana, level, experience)
{

}

void Guerrier::dispPersoType() const
{
    std::cout << "Je suis un guerrier !";
}

void Guerrier::receiveDamages(int &damages, int armor)
{

    if(armor > damages && damages != 0)
       {
        damages = 1;
       }
    else if (damages == 0)
    {
        damages = 0;
    }
    else
       {
        damages = damages - armor;
       }
    Personnage::receiveDamages(damages);
}

