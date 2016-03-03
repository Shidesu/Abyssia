/*Class Guerrier qui hérite de la class abstraite Personnage.*/
#pragma once

#include "Damages.h"
#include "Personnage.h"
#include <math.h>
#include "Damages.h"

class Guerrier : public Personnage
{
public:
    Guerrier(int life = 200, int mana = 50, int armor = 20, int level = 1, int experience = 0);
    virtual void dispPersoType() const;
	void attack(Entity & cible, int damages, Damages::DamagesType typeDegats);

protected:

};
