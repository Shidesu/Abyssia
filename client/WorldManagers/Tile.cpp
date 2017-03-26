#include "Tile.h"



std::map<TileType, TileData> Tile::tiles;

void Tile::init()
{
	std::string names[] = {"dirt", "grass", "stone", "water"};
	TileType types[] = { DIRT, GRASS, STONE, WATER };
	int i(0);

	for (i; i < 4; i++) {
		tiles[types[i]].textures = make_unique<sf::Texture>(sf::Texture());
		tiles[types[i]].textures->loadFromFile("img/" + names[i] + ".png");
		tiles[types[i]].sprites = sf::Sprite(*tiles[types[i]].textures);
		tiles[types[i]].sprites.scale(sf::Vector2f(0.0625f,0.0625f));
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

void Tile::render(sf::RenderTarget & element)
{
	tiles[this->type].sprites.setPosition(static_cast<sf::Vector2f>(this->getAbsolutePosition()));
	element.draw(tiles[this->type].sprites);
}