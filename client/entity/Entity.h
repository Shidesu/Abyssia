#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <string>
#include <iostream>
#include <math.h>

class Entity
{
public:
	Entity(int life, int mana, float armor, bool alive = true);
	virtual ~Entity();
	virtual void attack(Entity &cible, float damages) = 0;
	virtual void receiveDamages(float &damages);
	int getMana() const;//Accesseur d'affichage du mana
	void setMana(int manaQuantity);//Accesseur modificateur du mana
	int getLife() const;//Accesseur d'affichage de la vie
	void setLife(int lifeQuantity);//Accesseur modificateur de la vie
	virtual float getArmor() const = 0;

protected:
	int m_mana;
	int m_life;
	bool m_alive;
	float m_armor;

};


#endif