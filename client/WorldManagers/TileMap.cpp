#include "TileMap.h"



TileMap::TileMap(weak_ptr<Chunk> chunk,int height, int width) : chunk(chunk), height(height), width(width)
{
	tiles.reserve(height);
	for (int i = 0; i < height; i++)
	{
		std::vector<shared_ptr<Tile>> tileLine = {};
		tileLine.reserve(width);
		tiles.push_back(tileLine);
	}
}

shared_ptr<Tile> TileMap::getTile(Position &position) const
{
	if (position.x >= width || position.y >= height)
		throw std::length_error("Attempted to get a Tile out of range");

	return tiles[position.x][position.y];
}

void TileMap::setTile(shared_ptr<Tile> tile, Position &position)
{
	tiles[position.x][position.y] = tile;
	if (tile != nullptr) {
		tile->setTileMap(shared_from_this());
		tile->setPosition(position);
	}
}

shared_ptr<Chunk> TileMap::getChunk()
{
	return chunk.lock();
}

void TileMap::render(sf::RenderTarget & element)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			getTile(Position(i, j))->render(element);
		}
	}
}
