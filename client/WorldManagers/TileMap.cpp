#include "TileMap.h"



TileMap::TileMap(weak_ptr<Chunk> chunk,int height, int width) : chunk(chunk), height(height), width(width)
{
	this->tiles.reserve(height);
	for (int i = 0; i < height; i++)
	{
		std::vector<shared_ptr<Tile>> tileLine = {};
		tileLine.reserve(width);
		this->tiles.push_back(tileLine);
	}
}

shared_ptr<Tile> TileMap::getTile(Position &position) const
{
	if (position.x >= this->width || position.y >= this->height)
		throw std::length_error("Attempted to get a Tile out of range");

	return this->tiles[position.x][position.y];
}

void TileMap::setTile(shared_ptr<Tile> tile, Position &position)
{
	this->tiles[position.x][position.y] = tile;
	if (tile != nullptr) {
		tile->setTileMap(shared_from_this());
		tile->setPosition(position);
	}
}

shared_ptr<Chunk> TileMap::getChunk()
{
	return this->chunk.lock();
}

void TileMap::render(sf::RenderTarget & element)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->getTile(Position(i, j))->render(element);
		}
	}
}
