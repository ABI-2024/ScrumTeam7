#include "Cripple.h"

#include "Window.h"
#include "Entity.h"

Cripple::Cripple(StatusEffect effect, Entity* Host)
	:StatusProc(effect, Host)
{}

Cripple::~Cripple()
{
}

void Cripple::update()
{
	EntityStatus* temp = host->getEntityStatus(); //Attack Sp. wird verändert
	temp->multi_Attackspeed = this->strength;

	if (activeDuration.getElapsedTime() >= duration) { //Zeitbegrenzung
		active = false;
	}
}
