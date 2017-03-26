#pragma once

#include <memory>

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
	public Renderable, enable_shared_from_this<Chunk>
{
protected:
	shared_ptr<TileMap> tileMap;
	Position position;
	weak_ptr<World> world;
public:
	Chunk(Position &position);
	Chunk();
	~Chunk();

	void render(sf::RenderTarget &element);

	shared_ptr<TileMap> getTileMap() const;
	void setTileMap(shared_ptr<TileMap> tileMap);

	Position getPosition() const;
	void setPosition(Position &position);

	shared_ptr<World> getWorld();
	void setWorld(weak_ptr<World> world);

};

