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
	Franz franzdebog("Franz", "Agressif", 200, 100, 10, 50, 100);
   
    testFonct(Guerrier);
    float degats = 0;
    Guerrier.receiveDamages(degats);
	cout << franzdebog.getMonsterType();

    cout << "Il vous reste " << Guerrier.getLife() << " points de vie !!" << endl;
    /*cout << test2.getPersoType();*/

        return 0;
}
