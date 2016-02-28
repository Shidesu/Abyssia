#include "..\entity\Entity.h"
#include "..\entity\Franz.h"
#include "..\entity\Guerrier.h"
#include "..\entity\Monster.h"
#include "..\entity\Personnage.h"
#include "..\json.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


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
