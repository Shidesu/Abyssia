#include "Entity.h"
#include "Damages.h"

Entity::Entity(int life, int mana, int armor, bool alive) : life(life), mana(mana), armor(armor), alive(alive)
{
}

Entity::~Entity()
{
}

void Entity::receiveDamages(Damages damages)
{
	
	int* damagesReceived = new int;
	
	if (damages.getTypeDamages() == Damages::DamagesType::Physical)
	{
	 *damagesReceived = damages.getDamages() * pow(0.99, this->getArmor());
	}

	this->setLife(this->getLife() - *damagesReceived);
	if (this->getLife() <= 0)
	{
		this->setLife(0);
		this->alive = false;
	}
	/*damages = (int)round(double(damages) * pow(0.99, this->getArmor()));

	*/
}

int Entity::getMana() const
{
	return this->mana;
}

void Entity::setMana(int manaQuantity)
{
	this->mana = manaQuantity;
}

int Entity::getLife() const
{
	return this->life;
}

void Entity::setLife(int lifeQuantity)
{
	this->life = lifeQuantity;
}

int Entity::getArmor() const
{
	return this->armor;
}

void Entity::setArmor(int armor)
{
	this->armor = armor;
}
