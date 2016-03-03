#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier(int life, int mana, int armor, int level, int experience) : Personnage::Personnage(life, mana, armor, level, experience)
{

}

Guerrier::~Guerrier()
{
}

void Guerrier::dispPersoType() const
{
	std::cout << "Je suis un guerrier !" << endl;
}

void Guerrier::attack(Entity & cible, int const & damages, Damages::DamagesType typeDegats)
{
	if (this->isAlive())
	{
		Damages damagesT(damages, this, typeDegats);
		//Damages damages(damages, this, Damages::DamagesType::Physical);
		cible.receiveDamages(damagesT);
	}
}

