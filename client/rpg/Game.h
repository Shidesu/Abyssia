#include "../entity/Personnage.h"
#include "../graph/PersonnageGraph.h"
#include "../entity/Guerrier.h"
#include "../entity/Monster.h"
#include "../entity/franz.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "../json.h"

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
};
