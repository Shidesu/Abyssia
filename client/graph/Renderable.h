#pragma once

#include "World.h"
class Renderable
{
public:
	Renderable();
	~Renderable();

	/*
		Render the object in the specified world
	*/
	virtual void render(World world) = 0;
};

