#include "World.h"



World::World()
{
	this->chunks = {};
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

std::vector<Chunk*> World::getChunks() const
{
	return this->chunks;
}

void World::setChunks(std::vector<Chunk*> chunks) 
{
	this->chunks = chunks;
}