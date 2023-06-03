#pragma once

#include "Entity.h"

#include "enums.h"



class BaseTower : public Entity
{
protected:

	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;
	sf::Time fireRateDiviation;

public:

	BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture);
	virtual ~BaseTower();

	sf::Vector2f getTilePosition() override;
	const CollisionType& getCollisionType() override;
	sf::FloatRect getFloaRect();
	sf::Vector2f getPosition();

	virtual void pauseEntitiy();
	virtual void continueEntitiy();
};




