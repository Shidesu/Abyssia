#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier(int life, int mana) : Personnage::Personnage(life, mana)
{

}

void Guerrier::dispPersoType() const
{
    std::cout << "Je suis un guerrier !";
}
