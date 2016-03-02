#include "..\entity\Entity.h"
#include "..\entity\Franz.h"
#include "..\entity\Guerrier.h"
#include "..\entity\Monster.h"
#include "..\entity\Personnage.h"
#include "..\json.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// The different window parameters
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 900

#pragma once
class Game
{
public:
	Game();
	~Game();

	// Le commencement
	void start();

	// Met tes tests ici
	void test();

	/*
	 * Récupère l'instance de Game
	 */
	static Game* getInstance();

	/*
	 * Récupère l'instance de sfml window
	 */
	sf::RenderWindow* getWindow() const;

	

protected:

	sf::RenderWindow *window;
	static Game *instance;
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;

	const std::string window_title = "RPG project";

	void initWindow();
};
