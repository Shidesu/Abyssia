#include "World.h"



World::World()
{
	this->entities = {};
}


World::~World()
{
}

void World::render(Renderable &element) {
	// Can change this in the future

}

std::vector<Entity*> World::getEntities() const
{
	return this->entities;
}

void World::setEntities(std::vector<Entity*> entities) 
{
	this->entities = entities;
}

Chunk * World::getChunk(Position &pos) const
{
	return chunks[pos.x][pos.y];
}

void World::setChunk(Position &pos, Chunk * chunk)
{
	chunks[pos.x][pos.y] = chunk;
	chunk->setPosition(pos);
	chunk->setWorld(this);
}