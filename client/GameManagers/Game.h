/*GAME.H
Définit les prototypes de déplacement du personnage ainsi que la création de la fenêtres et des entités graphiques.

Dernière Modification : 06/03/2016 à 01:20

*/

#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

#include "..\EntityManagers\Entity.h"
#include "..\EntityManagers\Franz.h"
#include "..\EntityManagers\Guerrier.h"
#include "..\EntityManagers\Monster.h"
#include "..\EntityManagers\Personnage.h"
#include "..\json.h"
#include "..\WorldManagers\TileMap.h"


// The different window parameters
#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 900

class Game
{
public:
	static shared_ptr<Game> create();
	~Game();

	// Le commencement
	void start();
	// Met tes tests ici
	void test();
	// Collisions avec les bords de la fenêtre
	void windowCollision(sf::Vector2f & last_position);
	void worldCollision(sf::Vector2f & last_pos);
	// Récupère l'instance de Game
	static shared_ptr<Game> getInstance();
	// Regroupe le clear, les draw et l'affichage
	void render();
	// Evenemnts de déplacement en temps réel
	void deplacement();
	// Autres événements ne nécessitant pas le temps réel
	void handleEvent(sf::Event event);
	// Récupère l'instance de sfml window
	shared_ptr<sf::RenderWindow> getWindow() const;
	// Charge les ressources
	int load();




protected:
	Game();

	int frameLimite = 120;
	float speed = 90;
	sf::Clock moveClock;
	shared_ptr<sf::RenderWindow> window;
	static shared_ptr<Game> instance;
	static bool isLaunched;
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;
	shared_ptr<TileMap> map;

	const std::string window_title = "Les Fresques Ancestrales : Abyssia";

	void initWindow();
};
