/*Class Guerrier qui h�rite de la class abstraite Personnage.*/
#ifndef DEF_GUERRIER
#define DEF_GUERRIER
#include "Personnage.h"

class Guerrier : public Personnage
{
public:
    Guerrier(int life, int mana);
    virtual void dispPersoType() const;

protected:

};
#endif
