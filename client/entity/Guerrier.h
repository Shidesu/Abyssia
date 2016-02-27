/*Class Guerrier qui hérite de la class abstraite Personnage.*/
#ifndef DEF_GUERRIER
#define DEF_GUERRIER
#include "Personnage.h"

class Guerrier : public Personnage
{
public:
    Guerrier(int life = 200, int mana = 50, int level = 1, int experience = 0 );
    virtual void dispPersoType() const;
    virtual void receiveDamages(int &damages, int armor=10);

protected:

};
#endif
