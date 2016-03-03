#include "Entity.h"
#include "Damages.h"

Entity::Entity(int life, int mana, int armor, int resistance, bool alive) : life(life), mana(mana), armor(armor), resistance(resistance), alive(alive)
{
}

Entity::~Entity()
{
}

void Entity::attack()
{
}

void Entity::receiveDamages(Damages damages)
{
	
	int* damagesReceived = new int(damages.getDamages());

	
	if (damages.getTypeDamages() == Damages::DamagesType::Physical)
	{
		*damagesReceived = *damagesReceived * pow(0.99, this->getArmor());
	}
	else if (damages.getTypeDamages() == Damages::DamagesType::Magic)
	{
		*damagesReceived = *damagesReceived * pow(0.99, this->getMagicResistance());
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

int Entity::getMagicResistance() const
{
	return this->resistance;
}

void Entity::setMagicResistance(int magicResistance)
{
	this->resistance = magicResistance;
}
