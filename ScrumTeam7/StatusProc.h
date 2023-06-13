#pragma once
#include "StatusEffect.h"

class Entity;

// StatusProc wird als Basesklasse für die Eigentliche StatusEffecte verwendet
class StatusProc abstract : public StatusEffect
{
protected:
	bool active;						// solange true bleibt dieser Statusproc active
	sf::Clock activeDuration;	// timer für wie lange dieser Statusproc active ist
	Entity* host;

public:
	StatusProc(StatusEffect, Entity* );
	virtual ~StatusProc();

	virtual void update() = 0;

	bool isActive();
};

