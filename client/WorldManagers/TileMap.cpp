#include "TileMap.h"



TileMap::TileMap(Chunk *chunk,int height, int width) : chunk(chunk), height(height), width(width)
{
	this->tiles.reserve(height);
	for (int i = 0; i < height; i++)
	{
		std::vector<Tile*> tileLine = {};
		tileLine.reserve(width);
		this->tiles.push_back(tileLine);
	}
}


TileMap::~TileMap()
{
	// delete all the tiles
	for (auto tileLine : this->tiles) {
		for (Tile *tile : tileLine) {
			delete tile;
		}
	}
}

Tile* TileMap::getTile(Position &position) const
{
	if (position.x >= this->width || position.y >= this->height)
		throw std::length_error("Attempted to get a Tile out of range");

	return this->tiles[position.x][position.y];
}

void TileMap::setTile(Tile * tile, Position &position)
{
	this->tiles[position.x][position.y] = tile;
	if (tile != nullptr) {
		tile->setTileMap(this);
		tile->setPosition(position);
	}
}

Chunk* TileMap::getChunk()
{
	return this->chunk;
}

void TileMap::render(Renderable & element)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->getTile(Position(i, j)).render(element);
		}
	}
}
