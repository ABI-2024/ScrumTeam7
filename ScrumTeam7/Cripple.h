#pragma once
#include "StatusProc.h"

class Cripple : public StatusProc
{
public:
	Cripple(StatusEffect, Entity*);
	virtual ~Cripple();

	void update() override;
};

