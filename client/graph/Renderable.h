#pragma once

class Renderable
{
public:
	Renderable();
	~Renderable();

	/*
		Render the object in the specified element
	*/
	virtual void render(Renderable &element);
};

