#include "StatusProc.h"

StatusProc::StatusProc(StatusEffect effect, Entity* Host)
	:StatusEffect(effect), host(Host), active(true)
{
	activeDuration.restart();
}

StatusProc::~StatusProc()
{
}

bool StatusProc::isActive()
{
	return active;
}
