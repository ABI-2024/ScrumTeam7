#include "Stun.h"

#include "Entity.h"
#include "Window.h"

Stun::Stun(StatusEffect effect, Entity* Host)
	:StatusProc(effect, Host), first(true)
{}

Stun::~Stun()
{
}

void Stun::update()
{
	EntityStatus* temp = host->getEntityStatus();
	temp->canAttack = false;
	temp->canWalk = false;
	
	if (first) {
		if (temp->moveable) {
			host->setPosition(host->getPosition()+ sf::Vector2f(strength,0));
		}
		first = false;
	}

	if (activeDuration.getElapsedTime() >= duration) {
		active = false;
	}
}