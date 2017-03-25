#include "Tile.h"

std::map<TileType, sf::Texture> Tile::textures;
std::map<TileType, sf::Sprite> Tile::sprites;

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

Tile::Tile(weak_ptr<TileMap> map, TileType type)
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

shared_ptr<TileMap> Tile::getTileMap() const
{
	return this->map.lock();
}

void Tile::setTileMap(weak_ptr<TileMap> map)
{
	if (!this->map.expired())this->getTileMap()->setTile(NULL, this->position);
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