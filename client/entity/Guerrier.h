/*Class Guerrier qui h�rite de la class abstraite Personnage.*/
#pragma once

#include "Damages.h"
#include "Personnage.h"
#include <math.h>
#include "Damages.h"
#include "Entity.h"

class Guerrier : public Personnage
{
public:
    Guerrier(int life = 200, int mana = 50, int armor = 20, int level = 1, int experience = 0);
	virtual ~Guerrier();
	virtual void attack(Entity & cible, int const& damages, Damages::DamagesType typeDegats);
    virtual void dispPersoType() const;
	

protected:

};
