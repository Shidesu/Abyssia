#include "entity\Personnage.h"
#include "graph\PersonnageGraph.h"
#include "entity\Guerrier.h"
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
    Guerrier Guerrier(10,10);

    testFonct(Guerrier);

    Guerrier.getLife();

    /*cout << test2.getPersoType();*/

        return 0;
}
