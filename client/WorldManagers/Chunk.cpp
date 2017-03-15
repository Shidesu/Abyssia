#include "Chunk.h"



Chunk::Chunk(Position &position) : position(position)
{
	this->tileMap = new TileMap(this, TILEMAP_HEIGHT, TILEMAP_WIDTH);
}

Chunk::Chunk()
{
}


Chunk::~Chunk()
{
}

void Chunk::render(Renderable &element)
{

}

TileMap * Chunk::getTileMap() const
{
	return this->tileMap;
}

void Chunk::setTileMap(TileMap * tileMap)
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

World * Chunk::getWorld()
{
	return this->world;
}

void Chunk::setWorld(World * world)
{
	this->world = world;
}