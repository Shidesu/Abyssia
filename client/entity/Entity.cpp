#include "Entity.h"

Entity::Entity(int life, int mana, float armor, bool alive) : m_life(life), m_mana(mana), m_armor(armor), m_alive(alive)
{
}

Entity::~Entity()
{
}

void Entity::receiveDamages(float & damages)
{
	damages = damages * pow(0.99, this->getArmor());

	damages = round(damages);

	this->setLife( this->getLife() - damages);
	if (this->getLife() <= 0)
	{
		this->setLife(0);
		this->m_alive = false;
	}
}

int Entity::getMana() const
{
	return this->m_mana;
}

void Entity::setMana(int manaQuantity)
{
	this->m_mana = manaQuantity;
}

int Entity::getLife() const
{
	return this->m_life;
}

void Entity::setLife(int lifeQuantity)
{
	this->m_life = lifeQuantity;
}