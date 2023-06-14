#pragma once

#include "Entity.h"

#include "enums.h"
#include "SFML/Audio.hpp"

class BaseEnemy : public Entity
{
protected:

	bool movable;
	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;

	static sf::SoundBuffer* bufferMale,* bufferFemale;
	static sf::Sound* male, *female;

public:
	static void loadSound();
	static void unloadSound();

	BaseEnemy(float Health,	sf::Vector2f tilePosition, sf::Texture* texture);
	virtual ~BaseEnemy();

	sf::Vector2f getTilePosition()  override;
	const CollisionType& getCollisionType() override;

	sf::FloatRect getFloaRect();

	sf::Vector2f getPosition();

	void takeDamage(float) override;

	virtual void pauseEntitiy();
	virtual void continueEntitiy();
};

