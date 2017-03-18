#pragma once

#include "SFML\System.hpp"

#include "Renderable.h"
#include "TileMap.h"
#include "World.h"

#define TILEMAP_HEIGHT 25
#define TILEMAP_WIDTH 25

class TileMap;
class World;
typedef sf::Vector2i Position;

class Chunk :
	public Renderable
{
protected:
	TileMap* tileMap;
	Position position;
	World* world;
public:
	Chunk(Position &position);
	Chunk();
	~Chunk();

	void render(Renderable &element);

	TileMap* getTileMap() const;
	void setTileMap(TileMap* tileMap);

	Position getPosition() const;
	void setPosition(Position &position);

	World* getWorld();
	void setWorld(World *world);

};

