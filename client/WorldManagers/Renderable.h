#pragma once

#include "SFML\Graphics.hpp"

class Renderable
{
public:
	Renderable();
	~Renderable();

	/*
		Render the object in the specified element
	*/
	virtual void render(sf::RenderTarget &element) = 0;
};

