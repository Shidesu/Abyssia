#include "rpg/Game.h"
#include <SFML\Graphics.hpp>

int main()
{
	// Les deux lignes nécessaires
	Game* game = new Game();
	game->start();

	return 0;
}
