#pragma once
#include "Entity.h"


class Damages 
{
public:

	typedef enum class damagesType
	{
		Physical, Magic, Brute
	} DamagesType;

	Damages(int damages, Entity* damagesSender, DamagesType typeDamages );
	int virtual getDamages();

	


protected:

	int damages;
	DamagesType typeDamages;
	Entity* Sender = NULL;
};