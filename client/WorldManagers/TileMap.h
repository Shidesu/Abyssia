#pragma once

#include <vector>

#include "Tile.h"
#include "Chunk.h"

using namespace std;

class Chunk;
class Tile;

class TileMap :
	public Renderable
{
public:
	TileMap(Chunk *chunk,int heigth, int width);
	~TileMap();
	Tile* getTile(Position &position) const;
	void setTile(Tile* tile, Position &position);
	Chunk* getChunk();
	void render(Renderable &element);

protected:
	std::vector<std::vector<Tile*>> tiles = {};
	int height;
	int width;
	Chunk *chunk;
	
};

