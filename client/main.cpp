#include "rpg/Game.h"
#include <SFML\Graphics.hpp>

int main()
{
	// Les deux lignes n�cessaires
	Game* game = new Game();
	game->start();

	return 0;
}
