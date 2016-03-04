#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include "Fight.h"

class Fight;
class Damages;

class Entity
{
public:
	
	typedef enum class entityType
	{
		Playable, PNJ, Ally, Ennemy
	} entityType;
	
	Entity(int life, int mana, int armor, int resistance, entityType unitType, bool alive = true);
	virtual ~Entity() = 0;
	virtual void attack();
	virtual void receiveDamages(Damages damages);
	int getMana() const;//Accesseur d'affichage du mana
	void setMana(int manaQuantity);//Accesseur modificateur du mana
	int getLife() const;//Accesseur d'affichage de la vie
	void setLife(int lifeQuantity);//Accesseur modificateur de la vie
	int getArmor() const;
	void setArmor(int armor);
	int getMagicResistance() const;
	void setMagicResistance(int magicResistance);

protected:
	int mana;
	int life;
	bool alive;
	int armor;
	int resistance;
	entityType unitType;

};
