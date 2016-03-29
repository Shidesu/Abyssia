#pragma once
#include "Renderable.h"
#include "TileMap.h"

#define TILEMAP_HEIGHT 25
#define TILEMAP_WIDTH 25

class Chunk :
	public Renderable
{
public:
	Chunk(Position &position);
	~Chunk();

	void render(Renderable &element);

	TileMap* getTileMap() const;
	Position getPosition() const;
	void setPosition(Position &position);

protected:
	TileMap *tileMap;
	Position position;
};

