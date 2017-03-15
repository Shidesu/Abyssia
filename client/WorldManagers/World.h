#pragma once

#include <vector>
#include "Renderable.h"
#include "../EntityManagers/Entity.h"
#include "Chunk.h"

#define CHUNKS_HEIGHT 16
#define CHUNKS_WIDTH 16

class World :
	public Renderable
{
protected:
	std::vector<Entity*> entities;
	Chunk* chunks[CHUNKS_WIDTH][CHUNKS_HEIGHT];

public:
	World();
	~World();

	void render(Renderable &element);

	std::vector<Entity*> getEntities() const;
	void setEntities(std::vector<Entity*> entities);

	Chunk* getChunk(Position &pos) const;
	void setChunk(Position &pos, Chunk* chunk);
};

