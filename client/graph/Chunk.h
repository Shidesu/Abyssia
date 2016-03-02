#pragma once
#include "Renderable.h"

class Chunk :
	public Renderable
{
public:
	Chunk();
	~Chunk();

	void render(Renderable &element);
};

