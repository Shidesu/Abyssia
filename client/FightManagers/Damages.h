#pragma once
#include <memory>
#include "../EntityManagers/Entity.h"

using namespace std;


class Damages 
{
public:

	typedef enum class damagesType
	{
		Physical, Magic, Brute
	} DamagesType;

	Damages(int damages, Entity* damagesSender, DamagesType typeDamages );
	int virtual getDamages();
	DamagesType getTypeDamages();

	


protected:

	int damages;
	DamagesType typeDamages;
	shared_ptr<Entity> Sender;
};