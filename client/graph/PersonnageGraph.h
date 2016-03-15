/*Fichier d'en-t�te de la classe abstraite PersonnageG
Regroupe les d�placements du personnages, les collisions [certainement temporairement], ainsi que la texturisation du personnage.

Cr��e le 25/02/2016 par Kao

Derni�re modification : 15/03/2016 20h18
*/
#pragma once

#include <string>
#include <iostream>
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>


#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 900


class PersonnageG
{
public:
	PersonnageG();
	//Les m�thodes de cette classe abstraite seront virtuelles, je d�finis donc le prototype du destructeur abstrait.
	virtual ~PersonnageG();
	void deplacement();
	void windowCollision();
	void worldCollision(sf::Vector2f & last_pos);

/*protected:*/
	float speed = 90;
	sf::Clock moveClock;
	sf::Texture sachiko;
	sf::Sprite Player;
	sf::RectangleShape testR = sf::RectangleShape(sf::Vector2f(5, 8));
	const int window_height = WINDOW_HEIGHT;
	const int window_width = WINDOW_WIDTH;
};
