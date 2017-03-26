#include "Tile.h"

std::map<TileType, unique_ptr<sf::Texture>> Tile::textures;
std::map<TileType, sf::Sprite> Tile::sprites;

void Tile::init()
{
	std::map<TileType, unique_ptr<sf::Texture>>::iterator index;
	std::map<TileType, sf::Sprite>::iterator it;
	std::string names[] = {"dirt", "grass", "stone", "water"};
	TileType types[] = { DIRT, GRASS, STONE, WATER };
	int i(0);

	for (index = Tile::textures.begin(); index != textures.end(); index++) {
		index->second = make_unique<sf::Texture>(sf::Texture());
		index->second->loadFromFile("img/" + names[i] + ".png");
		it->second = sf::Sprite(*index->second);
		it++; i++;
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