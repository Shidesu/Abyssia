#include "client\entity\Personnage.h"
#include "client\graph\PersonnageGraph.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Ma premiere fenetre SFML ! ");

    CircleShape carre(80, 4);
    /*carre.AddPoint(200, 200, Color(255, 255, 0), Color(255,255,255));
    carre.AddPoint(400, 200, Color(255, 255, 0), Color(255,0,0));
    carre.AddPoint(400, 400, Color(0, 255, 255), Color(0,255,0));
    carre.AddPoint(200, 400, Color(0, 255, 255), Color(0,0,255));*/
    /*carre.enableFill(true); // Remplissage activé
    carre.EnableOutline(true); // Bordures activées
    carre.SetOutlineWidth(20); // Bordures de taille 20 pixels
*/
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

        // Remplissage de l'écran (couleur noire par défaut)
        window.draw(carre);

        // Affichage de la fenêtre à l'écran
        window.display();
    }
    return 0;
}
