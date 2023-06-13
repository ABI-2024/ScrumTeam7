#pragma once
#include "StatusProc.h"

class Burn : public StatusProc
{
public:
	Burn(StatusEffect, Entity*);
	virtual ~Burn();

	void update() override;
};

