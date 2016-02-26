/*Fichier d'en-t�te de la classe abstraite Monster
Affichera les prototypes des fonctions utiis�es pour construire un monstre et ses variables associ�es
Les m_ sont utilis�s pour diff�rencier les variables m�thodes des autres.

Cr��e le 26/02/2016 par Kao

Derni�re modification : 26/02/2016 16h26
*/
#ifndef DEF_MONSTER
#define DEF_MONSTER
#include <string>
#include <iostream>

class Monster
{
public:
    Monster();
    virtual ~Monster();
    virtual std::string getMonsterType() const = 0;

protected:
std::string m_monsterType;


};
#endif
