/*GAME.H
Définit les prototypes de déplacement du personnage ainsi que la création de la fenêtres et des entités graphiques.

Dernière Modification : 06/03/2016 à 01:20

*/

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
#define WINDOW_HEIGHT 900
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
	// Collisions avec les bords de la fenêtre
	void windowCollision();
	void worldCollision(sf::Vector2f & last_pos);
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
	int load();



protected:
	int frameLimite = 120;
	float speed = 90;
	sf::Clock moveClock;
	sf::Texture sachiko;
	sf::Texture mario;
	sf::Sprite monster;
	sf::Sprite Player;
	sf::RenderWindow *window;
	static Game *instance;
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;
	sf::VertexArray cubeTestCollision;
	sf::RectangleShape testR = sf::RectangleShape(sf::Vector2f(5, 8));
	TileMap map;

	const std::string window_title = "Les Fresques Ancestrales : Abyssia";

	void initWindow();
};
