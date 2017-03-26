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
	return position;
}

void Tile::setPosition(Position &position)
{
	this->position = position;
}

shared_ptr<TileMap> Tile::getTileMap() const
{
	return map.lock();
}

void Tile::setTileMap(weak_ptr<TileMap> map)
{
	if (!this->map.expired())getTileMap()->setTile(nullptr, position);
	this->map = map;
}

Position Tile::getAbsolutePosition() const
{
	int x = TILEMAP_WIDTH * getTileMap()->getChunk()->getPosition().x+ position.x;
	int y = TILEMAP_HEIGHT * getTileMap()->getChunk()->getPosition().y + position.y;
	return Position(x, y);
}

void Tile::setAbsolutePosition(Position & position)
{
	int x = position.x - TILEMAP_WIDTH * getTileMap()->getChunk()->getPosition().x;
	int y = position.y - TILEMAP_HEIGHT * getTileMap()->getChunk()->getPosition().y;
	setPosition(Position(x,y));
}

void Tile::render(sf::RenderTarget & element)
{
	tiles[type].sprites.setPosition(static_cast<sf::Vector2f>(getAbsolutePosition()));
	element.draw(tiles[type].sprites);
}