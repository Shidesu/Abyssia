#include "client\entity\Personnage.h"
#include "client\graph\PersonnageGraph.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Ma premiere fenetre SFML ! ");

    CircleShape carre(80, 4); //la classe circleshape permet de faire des cubes car un cercle y est défini comme un polygône avec de nombreux sommets.
     carre.setFillColor(Color(100,250,50));
    // Boucle principale
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Affichage du carré
        window.draw(carre);

        // Affichage de la fenętre ŕ l'écran
        window.display();
    }
    return 0;
}