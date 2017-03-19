#pragma once

#include <map>

#include "SFML\Graphics.hpp"

#include "Renderable.h"
#include "TileMap.h"

/*
	The type of the TileType, can be solid ( entities can't go in) , ground ( entities can walk on it )
	or special
 */

typedef sf::Vector2i Position;

class TileMap;

enum TileType
{
	DIRT,
	GRASS,
	STONE,
	WATER
};


class Tile :
	public Renderable
{
public:
	static void init();

	Tile(TileMap* map, TileType type);
	~Tile();
	Position getPosition() const;
	void setPosition(Position &position);
	TileMap* getTileMap() const;
	void setTileMap(TileMap* map);
	Position getAbsolutePosition() const;
	void setAbsolutePosition(Position &position);

	void render(Renderable &element);

protected:
	TileMap *map;
	TileType *type;
	Position position;

	static std::map<TileType, sf::Texture> textures;
	static std::map<TileType, sf::Sprite> sprites;
};

