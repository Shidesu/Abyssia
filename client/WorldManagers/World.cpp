#include "World.h"



World::World()
{
	this->entities = {};
}


World::~World()
{
}

void World::render(sf::RenderTarget &element) {
	// Can change this in the future

}

std::vector<shared_ptr<Entity>> World::getEntities() const
{
	return this->entities;
}

void World::setEntities(std::vector<shared_ptr<Entity>> entities) 
{
	this->entities = entities;
}

shared_ptr<Chunk> World::getChunk(Position &pos) const
{
	return chunks[pos.x][pos.y];
}

void World::setChunk(Position &pos, shared_ptr<Chunk> chunk)
{
	chunks[pos.x][pos.y] = chunk;
	chunk->setPosition(pos);
	chunk->setWorld(shared_from_this());
}