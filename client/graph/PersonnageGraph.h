/*Fichier d'en-tête de la classe abstraite PersonnageG
Affichera les prototypes des fonctions utiisées pour afficher un personnage.

Créée le 25/02/2016 par Kao

Dernière modification : 25/02/2016 18h18
*/
#ifndef DEF_PERSONNAGEGRAPH
#define DEF_PERSONNAGEGRAPH
#include <string>
#include <iostream>

class PersonnageG
{
public:
	PersonnageG();
	//Les méthodes de cette classe abstraite seront virtuelles, je définis donc le prototype du destructeur abstrait.
	virtual ~PersonnageG();
	virtual void createPersonnage() = 0;

protected:
	//Je sais pas encore les variables dont on aura besoin dooooonc voilà.
};
#endif
