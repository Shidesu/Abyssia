#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 900

#pragma once
class Movements {
public: 
	void deplacement();
	void leftDeplacement();
	void rightDeplacement();
	void topDeplacement();
	void botDeplacement();
	void windowCollision();
	void worldCollision(sf::Vector2f & last_pos);

protected:
	float speed = 90;
	sf::Clock moveClock;
	sf::Texture sachiko;
	sf::Sprite player;
	sf::RectangleShape testR = sf::RectangleShape(sf::Vector2f(5, 8));
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;
};