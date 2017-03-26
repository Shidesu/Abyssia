#include "Entity.h"
#include "../FightManagers/Damages.h"

Entity::Entity(int life, int mana, int armor, int resistance, entityType unitType, std::string textureName, bool alive) : life(life), mana(mana), armor(armor), resistance(resistance), unitType(unitType), alive(alive)
{
	//this->entityTexture.loadFromFile(textureName);
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
		*damagesReceived = (int)round(*damagesReceived * pow(0.99, getArmor()));
	}
	else if (damages.getTypeDamages() == Damages::DamagesType::Magic)
	{
		*damagesReceived = (int)round(*damagesReceived * pow(0.99, getMagicResistance()));
	}
		
		setLife(getLife() - *damagesReceived);
	if (getLife() <= 0)
	{
		setLife(0);
		alive = false;
	}
	/*damages = (int)round(double(damages) * pow(0.99, this->getArmor()));

	*/
}

int Entity::getMana() const
{
	return mana;
}

void Entity::setMana(int manaQuantity)
{
	this->mana = manaQuantity;
}

int Entity::getLife() const
{
	return life;
}

void Entity::setLife(int lifeQuantity)
{
	this->life = lifeQuantity;
}

int Entity::getArmor() const
{
	return armor;
}

void Entity::setArmor(int armor)
{
	this->armor = armor;
}

int Entity::getMagicResistance() const
{
	return resistance;
}

void Entity::setMagicResistance(int magicResistance)
{
	this->resistance = magicResistance;
}
