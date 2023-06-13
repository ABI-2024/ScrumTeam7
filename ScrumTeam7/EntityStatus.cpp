#include "EntityStatus.h"

EntityStatus::EntityStatus()
	: alive(true), moveable(true), canWalk(true) , canAttack(true),
 multi_Attackspeed(1.f), multi_WalkingSpeed(1.f),
 multi_Damage(1.f), multi_TakenDamage(1.f)
{}

EntityStatus::EntityStatus(bool alive, bool moveable, bool canWalk, bool canAttack)
	: alive(alive), moveable(moveable), canWalk(canWalk), canAttack(canAttack),
multi_Attackspeed(1.f), multi_WalkingSpeed(1.f),
multi_Damage(1.f), multi_TakenDamage(1.f)
{}

EntityStatus::~EntityStatus()
{
}
