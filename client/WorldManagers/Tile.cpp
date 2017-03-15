#include "Tile.h"


void Tile::init()
{
	std::string names[] = {"dirt", "grass", "stone", "water"};
	TileType types[] = { DIRT, GRASS, STONE, WATER };

	for (int index = 0; index < 4; index++) {
		textures[types[index]] = sf::Texture();
		textures[types[index]].loadFromFile("img/" + names[index] + ".png");
		sprites[types[index]] = sf::Sprite(textures[types[index]]);
	}
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
	int x = TILEMAP_WIDTH * this->getTileMap()->getChunk()->getPosition().first + this->position.first;
	int y = TILEMAP_HEIGHT * this->getTileMap()->getChunk()->getPosition().second + this->position.second;
	return std::make_pair(x, y);
}

void Tile::setAbsolutePosition(Position & position)
{
	int x = position.first - TILEMAP_WIDTH * this->getTileMap()->getChunk()->getPosition().first;
	int y = position.second - TILEMAP_HEIGHT * this->getTileMap()->getChunk()->getPosition().second;
	this->setPosition(std::make_pair(x, y));
}

void Tile::render(Renderable & element)
{
}