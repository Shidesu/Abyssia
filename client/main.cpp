#include "entity\Personnage.h"
#include "graph\PersonnageGraph.h"
#include "entity\Guerrier.h"
#include "entity\Monster.h"
#include "entity\franz.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

void testFonct(Personnage const& p)
{
    p.dispPersoType();
}

int main()
{

	Guerrier Guerrier(100, 50);
	Franz franzdebog("Franz", "Agressif", 100, 100, 0, 50, 100);
		   
    testFonct(Guerrier);
	cout << franzdebog.getMonsterType() << endl;

	cout << "Le combat commence !" << endl;

	while (Guerrier.isAlive() && franzdebog.isAlive())
	{		
		Guerrier.attack(franzdebog, 5);

		cout << "Combat toujours en cours !" << endl;

		franzdebog.attack(Guerrier, 5);

		system("pause");

	}

	system("pause");

   /* cout << "Il vous reste " << Guerrier.getLife() << " points de vie !!" << endl;*/
    

        return 0;
}
