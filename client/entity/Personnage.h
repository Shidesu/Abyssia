/*Fichier d'en-t�te de la classe abstraite Personnage
Affichera les prototypes des fonctions utiis�es pour construire un personnages et ses variables associ�es
Les m_ sont utilis�s pour diff�rencier les variables m�thodes des autres.

Cr��e le 25/02/2016 par Kao

Derni�re modification : 25/02/2016 18h18
*/
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE
#include "Entity.h"
#include <string>
#include <iostream>

class Personnage : public Entity
{
public:
	Personnage(int life = 100, int mana = 100, float armor = 10, int level = 1, int experience = 0, bool alive = true);
    virtual ~Personnage();
	bool isAlive();
	virtual void receiveDamages(int damages); //Les prototypes sont des prototypes dans tous les sens du terme. Certainement modifi� dans le futur
	int getMana() const;//Accesseur d'affichage du mana
    void setMana(int manaQuantity);//Accesseur modificateur du mana
	int getLife() const;//Accesseur d'affichage de la vie
	void setLife(int lifeQuantity);//Accesseur modificateur de la vie
	int getXP() const;//Accesseur d'affichage de l'experience
	void setXP(int XPQuantity);//Accesseur modificateur de l'experience
	virtual void dispPersoType() const = 0; //Rend la classe abstraite et donne le type de personnage
//Fonction potentielle :
//	bool isLevelUp(Personnage &personnage, ...);


protected:
	int m_experience;
	int m_level;
	std::string m_persoType;
	float m_armor;

};

#endif // DEF_PERSONNAGE
