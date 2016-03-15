#include "rpg/Game.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include "graph\TileMap.h"



int main()
{
	// Les deux lignes nécessaires
	Game* game = new Game();
	game->start();

	return 0;
}

