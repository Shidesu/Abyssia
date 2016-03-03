#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier(int life, int mana, int armor, int level, int experience) : Personnage::Personnage(life, mana, armor, level, experience)
{

}

void Guerrier::dispPersoType() const
{
	std::cout << "Je suis un guerrier !" << endl;
}

void Guerrier::attack(Entity & cible, int damages, Damages::DamagesType typeDegats)
{
	Damages damagesT(damages, this, typeDegats);
	//Damages damages(damages, this, Damages::DamagesType::Physical);
	cible.receiveDamages(damagesT);
}

