#pragma once

#include <string>
#include <iostream>
#include <math.h>

class Damages;

class Entity
{
public:
	Entity(int life, int mana, int armor, bool alive = true);
	virtual ~Entity();
	virtual void attack() = 0;
	virtual void receiveDamages(Damages damages);
	int getMana() const;//Accesseur d'affichage du mana
	void setMana(int manaQuantity);//Accesseur modificateur du mana
	int getLife() const;//Accesseur d'affichage de la vie
	void setLife(int lifeQuantity);//Accesseur modificateur de la vie
	int getArmor() const;
	void setArmor(int armor);

protected:
	int mana;
	int life;
	bool alive;
	int armor;

};
