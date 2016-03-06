/*Fichier d'en-t�te de la classe abstraite Personnage
Affichera les prototypes des fonctions utiis�es pour construire un personnages et ses variables associ�es
Les m_ sont utilis�s pour diff�rencier les variables m�thodes des autres.

Cr��e le 25/02/2016 par Kao

Derni�re modification : 25/02/2016 18h18
*/
#pragma once
#include "Entity.h"
#include <string>
#include <iostream>
#include "Damages.h"

class Personnage : public Entity
{
public:
	Personnage(int life = 100, int mana = 100, int armor = 10, entityType unitType = entityType::PNJ, int resistance = 10, int level = 1, int experience = 0, bool alive = true);
    virtual ~Personnage();
	virtual void attack(Entity & cible, int const& damages, Damages::DamagesType typeDegats) = 0;
	bool isAlive();
	virtual void receiveDamages(Damages damages); //Les prototypes sont des prototypes dans tous les sens du terme. Certainement modifi� dans le futur
	int getExperience() const;//Accesseur d'affichage de l'experience
	void setExperience(int experience);//Accesseur modificateur de l'experience
	virtual void dispPersoType(); //Rend la classe abstraite et donne le type de personnage
//Fonction potentielle :
//	bool isLevelUp(Personnage &personnage, ...);


protected:
	int experience;
	int level;
	std::string persoType;


};
