#pragma once

#include <vector>

#include "Tile.h"
#include "../graph/Chunk.h"

using namespace std;

class TileMap
{
public:
	TileMap(Chunk *chunk,int heigth, int width);
	~TileMap();
	Tile* getTile(Position &position) const;
	void setTile(Tile* tile, Position &position);
	Chunk* getChunk();

protected:
	std::vector<std::vector<Tile*>> tiles = {};
	int height;
	int width;
	Chunk *chunk;
	
};

