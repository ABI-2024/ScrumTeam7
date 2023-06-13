#pragma once

// EntityStatus beinhält Statuszustände und multiplikator für Entities
class EntityStatus
{
public:
	bool alive, moveable,canWalk, canAttack;

	float multi_Attackspeed, multi_WalkingSpeed;
	float multi_Damage, multi_TakenDamage;

	EntityStatus();
	EntityStatus(bool, bool ,bool ,bool);
	~EntityStatus();
};

