#pragma once

#include <map>
#include <unordered_map>
#include <memory>

#include "SFML\Graphics.hpp"

#include "Renderable.h"
#include "TileMap.h"

/*
	The type of the TileType, can be solid ( entities can't go in) , ground ( entities can walk on it )
	or special
 */
using namespace std;

typedef sf::Vector2i Position;

class TileMap;

enum TileType
{
	DIRT,
	GRASS,
	STONE,
	WATER
};

struct TileData {
	unique_ptr<sf::Texture> textures;
	sf::Sprite sprites;

};


class Tile :
	public Renderable
{
public:
	static void init();

	Tile(weak_ptr<TileMap> map, TileType type);
	~Tile();
	Position getPosition() const;
	void setPosition(Position &position);
	shared_ptr<TileMap> getTileMap() const;
	void setTileMap(weak_ptr<TileMap> map);
	Position getAbsolutePosition() const;
	void setAbsolutePosition(Position &position);

	void render(sf::RenderTarget &element);

protected:
	weak_ptr<TileMap> map;
	TileType type;
	Position position;

	static std::map<TileType, TileData> tiles;
};

