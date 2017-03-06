#include "GameManagers/Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "WorldManagers/TileMap.h"


int main()
{
	// Les deux lignes nécessaires
	Game* game = new Game();
	game->start();

	return 0;
}

