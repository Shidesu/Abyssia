/*Fichier d'en-t�te de la classe abstraite Monster
Affichera les prototypes des fonctions utiis�es pour construire un monstre et ses variables associ�es
Les m_ sont utilis�s pour diff�rencier les variables m�thodes des autres.

Cr��e le 26/02/2016 par Kao

Derni�re modification : 26/02/2016 16h26
*/
#ifndef DEF_MONSTER
#define DEF_MONSTER
#include "Entity.h"
#include <string>
#include <iostream>

class Monster : public Entity
{
public:
    Monster(std::string monsterType, std::string monsterName, int life = 100, int mana = 100, float armor = 22.3, int XPGiven = 20, int goldGiven = 50);
    virtual ~Monster();
    virtual std::string getMonsterType() const = 0;
	virtual void receiveDamages(float & damages);
	virtual float getArmor() const;
	virtual int getLife() const;
	virtual void setLife(int lifeQuantity);
	virtual bool isAlive();

protected:
std::string m_monsterType;
std::string m_monsterName;
int m_experienceGiven;
int m_goldGiven;


};
#endif
