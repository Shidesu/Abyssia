/*Fichier d'en-tête de la classe abstraite Monster
Affichera les prototypes des fonctions utiisées pour construire un monstre et ses variables associées
Les m_ sont utilisés pour différencier les variables méthodes des autres.

Créée le 26/02/2016 par Kao

Dernière modification : 26/02/2016 16h26
*/
#ifndef DEF_MONSTER
#define DEF_MONSTER
#include "Entity.h"
#include <string>
#include <iostream>

class Monster : public Entity
{
public:
    Monster(std::string monsterType, std::string monsterName, int life = 100, int mana = 100, int armor = 22, int XPGiven = 20, int goldGiven = 50);
    virtual ~Monster();
	virtual std::string getMonsterName() const;
    virtual std::string getMonsterType() const = 0;
	virtual void receiveDamages(int damages);
	virtual bool isAlive();

protected:
	std::string monsterType;
	std::string monsterName;
	int experienceGiven;
	int goldGiven;


};
#endif
