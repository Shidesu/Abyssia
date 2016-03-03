#include "Damages.h"

Damages::Damages(int damages, Entity * damagesSender, DamagesType typeDegats) : damages(damages), Sender(damagesSender), typeDamages(typeDegats)
{
}

int Damages::getDamages()
{
	return damages;
}

Damages::DamagesType Damages::getTypeDamages()
{
	return this->typeDamages;
}
