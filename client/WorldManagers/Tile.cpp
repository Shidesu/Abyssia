#include "Tile.h"

bool operator<(TileType & a, TileType & b)
{
	return (int) a < (int) b;
}

void Tile::init()
{
	/*
	std::string names[] = {"dirt", "grass", "stone", "water"};
	TileType types[] = { DIRT, GRASS, STONE, WATER };

	for (int index = 0; index < 4; index++) {
		TileTypeTextures[types[index]] = sf::Texture();
		TileTypeTextures[types[index]].loadFromFile("img/" + names[index] + ".png");
		TileTypeSprites[types[index]] = sf::Sprite(TileTypeTextures[types[index]]);
	}
	*/
}

Tile::Tile(TileMap * map, TileType type)
{
}

Tile::~Tile()
{
}

Position Tile::getPosition() const
{
	return this->position;
}

void Tile::setPosition(Position &position)
{
	this->position = position;
}

TileMap * Tile::getTileMap() const
{
	return this->map;
}

void Tile::setTileMap(TileMap * map)
{
	if (this->map != nullptr)this->map->setTile(nullptr, this->position);
	this->map = map;
}

Position Tile::getAbsolutePosition() const
{
	int x = TILEMAP_WIDTH * this->getTileMap()->getChunk()->getPosition().x+ this->position.x;
	int y = TILEMAP_HEIGHT * this->getTileMap()->getChunk()->getPosition().y + this->position.y;
	return Position(x, y);
}

void Tile::setAbsolutePosition(Position & position)
{
	int x = position.x - TILEMAP_WIDTH * this->getTileMap()->getChunk()->getPosition().x;
	int y = position.y - TILEMAP_HEIGHT * this->getTileMap()->getChunk()->getPosition().y;
	this->setPosition(Position(x,y));
}

void Tile::render(Renderable & element)
{
}