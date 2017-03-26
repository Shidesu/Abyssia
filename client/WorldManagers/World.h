#pragma once

#include <vector>
#include "Renderable.h"
#include "../EntityManagers/Entity.h"
#include "Chunk.h"

#define CHUNKS_HEIGHT 16
#define CHUNKS_WIDTH 16

using namespace std;

class Chunk;
typedef sf::Vector2i Position;

class World :
	public Renderable, enable_shared_from_this<World>
{
protected:
	std::vector<shared_ptr<Entity>> entities;
	shared_ptr<Chunk> chunks[CHUNKS_WIDTH][CHUNKS_HEIGHT];

public:
	World();
	~World();

	void render(sf::RenderTarget &element);

	std::vector<shared_ptr<Entity>> getEntities() const;
	void setEntities(std::vector<shared_ptr<Entity>> entities);

	shared_ptr<Chunk> getChunk(Position &pos) const;
	void setChunk(Position &pos, shared_ptr<Chunk> chunk);
};

