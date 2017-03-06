/*GAME.H
D�finit les prototypes de d�placement du personnage ainsi que la cr�ation de la fen�tres et des entit�s graphiques.

Derni�re Modification : 06/03/2016 � 01:20

*/

#include <cstdlib>
#include <iostream>
#include <string>
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
	// Collisions avec les bords de la fen�tre
	void windowCollision(sf::Vector2f & last_position);
	void worldCollision(sf::Vector2f & last_pos);
	// R�cup�re l'instance de Game
	static Game* getInstance();
	// Regroupe le clear, les draw et l'affichage
	void render();
	// Evenemnts de d�placement en temps r�el
	void deplacement();
	// Autres �v�nements ne n�cessitant pas le temps r�el
	void handleEvent(sf::Event event);
	// R�cup�re l'instance de sfml window
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
	TileMap* map = nullptr;

	const std::string window_title = "Les Fresques Ancestrales : Abyssia";

	void initWindow();
};
