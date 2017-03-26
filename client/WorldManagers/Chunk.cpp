#include "Chunk.h"



Chunk::Chunk(Position &position) : position(position)
{
	tileMap = make_shared<TileMap>(shared_from_this(), TILEMAP_HEIGHT, TILEMAP_WIDTH);
}

Chunk::Chunk()
{
}


Chunk::~Chunk()
{
}

void Chunk::render(sf::RenderTarget &element)
{
	tileMap->render(element);
}

shared_ptr<TileMap> Chunk::getTileMap() const
{
	return tileMap;
}

void Chunk::setTileMap(shared_ptr<TileMap> tileMap)
{
	this->tileMap = tileMap;
}

Position Chunk::getPosition() const
{
	return position;
}

void Chunk::setPosition(Position & position)
{
	this->position = position;
}

shared_ptr<World> Chunk::getWorld()
{
	return world.lock();
}

void Chunk::setWorld(weak_ptr<World> world)
{
	this->world = world;
}