#include "Tile.h"



std::map<TileType, TileData> Tile::tiles;

void Tile::init()
{
	std::string names[] = {"dirt", "grass", "stone", "water"};
	TileType types[] = { DIRT, GRASS, STONE, WATER };
	int i(0);

	for (auto index = Tile::tiles.begin(); index != tiles.end(); index++, i++) {
		index->second.textures = make_unique<sf::Texture>(sf::Texture());
		index->second.textures->loadFromFile("img/" + names[i] + ".png");
		index->second.sprites = sf::Sprite(*index->second.textures);	
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