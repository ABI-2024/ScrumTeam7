#include "StatusEffect.h"

StatusEffect::StatusEffect(StatusType Type, int DurationMiliseconds, float Strength)
	:type(Type), duration(sf::milliseconds(DurationMiliseconds)), strength(Strength)
{}

StatusEffect::StatusEffect(StatusType Type, sf::Time Duration, float Strength)
	: type(Type), duration(Duration), strength(Strength)
{}

StatusType StatusEffect::getType()
{
	return type;
}

StatusEffect::~StatusEffect()
{
}
