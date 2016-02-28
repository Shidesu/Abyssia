#pragma once
#include "Renderable.h"
class World :
	public Renderable
{
public:
	World();
	~World();

	void render(World world);
};

