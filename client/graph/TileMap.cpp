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
	if (position.first >= this->width || position.second >= this->height)
		throw std::length_error("Attempted to get a Tile out of range");

	return this->tiles[position.second][position.first];
}

void TileMap::setTile(Tile * tile, Position &position)
{
	this->tiles[position.second][position.first] = tile;
	if (tile != nullptr) {
		tile->setTileMap(this);
		tile->setPosition(position);
	}
}

Chunk* TileMap::getChunk()
{
	return this->chunk;
}
