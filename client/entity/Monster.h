/*Fichier d'en-tête de la classe abstraite Monster
Affichera les prototypes des fonctions utiisées pour construire un monstre et ses variables associées
Les m_ sont utilisés pour différencier les variables méthodes des autres.

Créée le 26/02/2016 par Kao

Dernière modification : 26/02/2016 16h26
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
