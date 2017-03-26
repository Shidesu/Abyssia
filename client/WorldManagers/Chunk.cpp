#include "Chunk.h"



Chunk::Chunk(Position &position) : position(position)
{
	this->tileMap = make_shared<TileMap>(TileMap(shared_from_this(), TILEMAP_HEIGHT, TILEMAP_WIDTH));
}

Chunk::Chunk()
{
}


Chunk::~Chunk()
{
}

void Chunk::render(sf::RenderTarget &element)
{
	this->tileMap->render(element);
}

shared_ptr<TileMap> Chunk::getTileMap() const
{
	return this->tileMap;
}

void Chunk::setTileMap(shared_ptr<TileMap> tileMap)
{
	this->tileMap = tileMap;
}

Position Chunk::getPosition() const
{
	return this->position;
}

void Chunk::setPosition(Position & position)
{
	this->position = position;
}

shared_ptr<World> Chunk::getWorld()
{
	return this->world.lock();
}

void Chunk::setWorld(weak_ptr<World> world)
{
	this->world = world;
}