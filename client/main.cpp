#include "GameManagers/Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
	// Les deux lignes n�cessaires
	shared_ptr<Game> game = Game::create();
	game->start();

	return 0;
}

