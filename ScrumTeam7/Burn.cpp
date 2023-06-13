#include "Burn.h"

#include "Window.h"
#include "Entity.h"

Burn::Burn(StatusEffect effect, Entity* Host)
	:StatusProc(effect, Host)
{}

Burn::~Burn()
{
}

void Burn::update()
{
	this->host->takeDamage(strength*dt);

	if (activeDuration.getElapsedTime() >= duration) {
		active = false;
	}
}
