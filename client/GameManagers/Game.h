/*GAME.H
D�finit les prototypes de d�placement du personnage ainsi que la cr�ation de la fen�tres et des entit�s graphiques.

Derni�re Modification : 06/03/2016 � 01:20

*/

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "..\Tools\macros.h"
#include "..\EntityManagers\Entity.h"
#include "..\EntityManagers\Franz.h"
#include "..\EntityManagers\Guerrier.h"
#include "..\EntityManagers\Monster.h"
#include "..\EntityManagers\Personnage.h"
#include "..\WorldManagers\TileMap.h"


// The different window parameters
#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 900

class Game :
	public pointeur_intelligent<Game>
{
public:
	static Game::ps create();
	~Game();

	// Le commencement
	void start();
	// Met tes tests ici
	void test();
	// Collisions avec les bords de la fen�tre
	void windowCollision(sf::Vector2f & last_position);
	void worldCollision(sf::Vector2f & last_pos);
	// R�cup�re l'instance de Game
	static Game::ps getInstance();
	// Regroupe le clear, les draw et l'affichage
	void render();
	// Evenemnts de d�placement en temps r�el
	void deplacement();
	// Autres �v�nements ne n�cessitant pas le temps r�el
	void handleEvent(sf::Event event);
	// R�cup�re l'instance de sfml window
	shared_ptr<sf::RenderTarget> getWindow() const;
	// Charge les ressources
	int load();




protected:
	Game();

	int frameLimite = 120;
	float speed = 90;
	sf::Clock moveClock;
	shared_ptr<sf::RenderWindow> window;
	static Game::ps instance;
	static bool isLaunched;
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;
	shared_ptr<TileMap> map;

	const std::string window_title = "Les Fresques Ancestrales : Abyssia";

	void initWindow();
};
