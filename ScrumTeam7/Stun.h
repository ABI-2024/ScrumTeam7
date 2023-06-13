#pragma once

#include "StatusProc.h"

class Stun : public StatusProc
{
	bool first;
public:
	Stun(StatusEffect, Entity*);
	virtual ~Stun();

	void update() override;
};

