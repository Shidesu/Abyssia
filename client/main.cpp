#include "entity\Personnage.h"
#include "graph\PersonnageGraph.h"
#include "entity\Guerrier.h"
#include "entity\Monster.h"
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

    Guerrier Guerrier(100);
    while(Guerrier.isAlive()) //Attention dans l'étât actuel une attaque de 0 dégâts lance une boucle infinie :D
    {
    testFonct(Guerrier);
    int degats = 0;
    Guerrier.receiveDamages(degats , 10);
    }
    cout << "Il vous reste " << Guerrier.getLife() << " points de vie !!" << endl;
    /*cout << test2.getPersoType();*/

        return 0;
}
