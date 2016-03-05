#include "rpg/Game.h"
#include "graph\TileMap.h"
#include <SFML\Graphics.hpp>

using namespace std;
//using namespace nlohmann;
/*
void testFonct(Personnage const& p)
{
    p.dispPersoType();
}
*/

int main()
{
	// Les deux lignes nécessaire
	Game* game = new Game();
	game->start();

	return 0;
}
