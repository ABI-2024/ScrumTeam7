#pragma once

#include "Entity.h"

#include "enums.h"
#include "SFML/Audio.hpp"



class BaseTower : public Entity
{
protected:

	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;
	sf::Time fireRateDiviation;

	static bool enemyOnLines[5];

	static sf::SoundBuffer* bufferMale, * bufferFemale;
	static sf::Sound* male, * female;

public:
	static void loadSound();
	static void unloadSound();

	static void areEnemiesOnLine(std::vector<Entity*>* enemies);

	BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture);
	virtual ~BaseTower();

	sf::Vector2f getTilePosition() override;
	const CollisionType& getCollisionType() override;
	sf::FloatRect getFloaRect();
	sf::Vector2f getPosition();

	virtual void pauseEntitiy();
	virtual void continueEntitiy();
};




