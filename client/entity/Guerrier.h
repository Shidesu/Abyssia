/*Class Guerrier qui h�rite de la class abstraite Personnage.*/
#ifndef DEF_GUERRIER
#define DEF_GUERRIER
#include "Personnage.h"
#include <math.h>

class Guerrier : public Personnage
{
public:
    Guerrier(int life = 200, int mana = 50, float armor = 20, int level = 1, int experience = 0);
    virtual void dispPersoType() const;
    virtual void receiveDamages(float &damages);
	float getArmor() const;
	void setArmor(float newArmorValue);
	void attack(Entity &cible, float damages = 50);

protected:
	float m_armor;

};
#endif
