#ifndef DEF_FRANZ
#define DEF_FRANZ

#include "Monster.h"

class Franz : public Monster
{
public:
	Franz(std::string franzType = "Franz", std::string franzName = "", int life = 20, int mana = 10, float armor = 0, int XPGiven = 5, int goldGiven = 10);
	virtual ~Franz();
	std::string getMonsterType() const;
	virtual void receiveDamages(float &damages);
	void attack(Entity &cible, float damages = 25);

protected:

};

#endif