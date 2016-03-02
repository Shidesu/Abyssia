#pragma once

#include <vector>
#include "Renderable.h"
#include "../entity/Entity.h"
#include "Chunk.h"

class World :
	public Renderable
{
public:
	World();
	~World();

	void render(Renderable &element);

	std::vector<Entity*> getEntities() const;
	void setEntities(std::vector<Entity*> entities);

	std::vector<Chunk*> getChunks() const;
	void setChunks(std::vector<Chunk*> chunks);

protected:
	std::vector<Entity*> entities;
	std::vector<Chunk*> chunks;
};

