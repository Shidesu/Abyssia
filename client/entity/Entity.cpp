#include "Entity.h"

Entity::Entity(int life, int mana, float armor, bool alive) : m_life(life), m_mana(mana), m_alive(alive), m_armor(armor)
{
}

Entity::~Entity()
{
}
