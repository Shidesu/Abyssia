#include "entity\Personnage.h"
#include "graph\PersonnageGraph.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Ma premiere fenetre SFML ! ");
    Vector2f vect(150, 50);//on définit un vecteur de déplacement
    CircleShape carre(80, 4); //la classe circleshape permet de faire des cubes car un cercle y est défini comme un polygône avec de nombreux sommets.
    carre.move(vect);//on déplace le carré
    carre.rotate(45);//on redresse le carré et oui.
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
