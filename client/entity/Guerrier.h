/*Class Guerrier qui hérite de la class abstraite Personnage.*/

#include "Personnage.h"

class Guerrier : public Personnage
{
public:
    Guerrier(int life, int mana);
    virtual void dispPersoType() const;

protected:

};
