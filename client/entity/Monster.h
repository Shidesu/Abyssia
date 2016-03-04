/*Fichier d'en-t�te de la classe abstraite Monster
Affichera les prototypes des fonctions utiis�es pour construire un monstre et ses variables associ�es
Les m_ sont utilis�s pour diff�rencier les variables m�thodes des autres.

Cr��e le 26/02/2016 par Kao

Derni�re modification : 26/02/2016 16h26
*/
#pragma once

#include "Entity.h"
#include <string>
#include <iostream>
#include "Damages.h"

class Monster : public Entity
{
public:
    Monster(std::string monsterType, std::string monsterName, int life = 100, int mana = 100, int armor = 22, int resistance = 20, entityType unitType = entityType::Ennemy, int XPGiven = 20, int goldGiven = 50);
    virtual ~Monster();
	virtual std::string getMonsterName() const;
    virtual std::string getMonsterType() const = 0;
	virtual void receiveDamages(Damages damages);
	virtual bool isAlive();

protected:
	std::string monsterType;
	std::string monsterName;
	int experienceGiven;
	int goldGiven;


};