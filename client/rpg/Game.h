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
#include "..\graph\TileMap.h"


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
	// Récupère l'instance de Game
	static Game* getInstance();
	// Regroupe le clear, les draw et l'affichage
	void render();
	// Evenemnts de déplacement en temps réel
	void deplacement();
	// Autres événements ne nécessitant pas le temps réel
	void handleEvent(sf::Event event);
	// Récupère l'instance de sfml window
	sf::RenderWindow* getWindow() const;
	// Charge les ressources
	void load();

	

protected:
	
	int frameLimite = 120;
	float speed = 90;
	sf::Clock moveClock;
	sf::Texture marioFace, marioLeft;
	sf::Sprite Player;
	sf::RenderWindow *window;
	static Game *instance;
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;

	const std::string window_title = "Les Fresques Ancestrales : Abyssia";

	void initWindow();
};
