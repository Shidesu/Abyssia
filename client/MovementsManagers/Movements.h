#include <SFML/System.hpp>
//#include <utility>
//#include <iostream>
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 900

#pragma once
class Movements {
public: 
	static void deplacement();
	void collisions();

protected:
	float speed = 90;
	typedef std::pair<int, int> pos;
	sf::Clock moveClock;
	sf::Texture sachiko;
	sf::Sprite player;
	sf::RectangleShape testR = sf::RectangleShape(sf::Vector2f(5, 8));
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;
	std::string test;
};