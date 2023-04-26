#pragma once

#include "Entity.h"
#include "Window.h"

#include "SFML/Graphics.hpp"

enum class Status_Type
{
	non,
	stun,
	fire
};

class Status_Effect 
{

protected:
	Status_Type type;
	float effectProperty;
	sf::Time duration;

public:
	Status_Effect(Status_Type ntype, float nEffectProperty, sf::Time nDuration)
		: type(ntype), effectProperty(nEffectProperty), duration(nDuration)
	{};

	virtual ~Status_Effect() {	};

	const Status_Type& getType() 
	{
		return type;
	}
};

template<class T>
class  Status_Proc : public  Status_Effect
{

protected:
	sf::Clock timer;
	T* host;
public:
	bool active;

	Status_Proc(Status_Effect status_Effect, T* nHost)
		: Status_Effect(status_Effect), host(nHost) ,active(true)
	{
	}

	virtual ~Status_Proc() {
	}

	virtual void effect() 
	{
		switch (this->type)
		{
		case Status_Type::non:
			break;
		case Status_Type::stun:
			this->host->movable = false;
			if (this->effectProperty != 0) {
				this->host->body.move({ this->effectProperty, 0 });
				if (this->host->body.getPosition().x > 1600.f) {
					this->host->body.setPosition(1600.f, this->host->body.getPosition().y);
				}
				this->effectProperty = 0;
			}
			break;
		case Status_Type::fire:
			this->host->health -= this->effectProperty*dt;
			break;
		default:
			break;
		}

		if (this->timer.getElapsedTime() >= this->duration) {
			this->active = true;
			switch (this->type)
			{
			case Status_Type::stun:
				this->host->movable = true;
				break;
			default:
				break;
			}
		}
	}

};