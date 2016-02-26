/*Fichier d'en-t�te de la classe abstraite PersonnageG
Affichera les prototypes des fonctions utiis�es pour afficher un personnage.

Cr��e le 25/02/2016 par Kao

Derni�re modification : 25/02/2016 18h18
*/
#ifndef DEF_PERSONNAGEGRAPH
#define DEF_PERSONNAGEGRAPH
#include <string>
#include <iostream>

class PersonnageG
{
public:
	PersonnageG();
	//Les m�thodes de cette classe abstraite seront virtuelles, je d�finis donc le prototype du destructeur abstrait.
	virtual ~PersonnageG();
	virtual void createPersonnage() = 0;

protected:
	//Je sais pas encore les variables dont on aura besoin dooooonc voil�.
};
#endif
