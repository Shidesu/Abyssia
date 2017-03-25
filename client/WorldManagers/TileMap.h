#pragma once

#include <vector>
#include <memory>

#include "Tile.h"
#include "Chunk.h"

using namespace std;

class Chunk;
class Tile;

class TileMap :
	public Renderable, enable_shared_from_this<TileMap>
{
public:
	TileMap(weak_ptr<Chunk> chunk,int heigth, int width);
	shared_ptr<Tile> getTile(Position &position) const;
	void setTile(shared_ptr<Tile> tile, Position &position);
	shared_ptr<Chunk> getChunk();
	void render(Renderable &element);

protected:
	std::vector<std::vector<shared_ptr<Tile>>> tiles = {};
	int height;
	int width;
	weak_ptr<Chunk> chunk;
	
};

