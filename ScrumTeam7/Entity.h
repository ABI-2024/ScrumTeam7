#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "enums.h"
#include "EntityStatus.h"
#include "StatusProc.h"

enum class CollisionType : char {
	All = 0,

	ally,
	allyAmmo,
	enemies
};


class Entity
{
protected:

	EntityStatus status;
	std::vector<StatusProc*>* statusprocs;

	static sf::Texture* shadowTexture;

	sf::RectangleShape body;
	sf::RectangleShape shadow;

	void updateStatusprocs(bool canWalk, bool canAttack);

public:
	static void loadTexture();
	static void unloadTexture();

	virtual void renderShadow();
	
	EntityStatus* getEntityStatus();
	sf::Vector2f getPosition();
	virtual sf::Vector2f getTilePosition();
	virtual const CollisionType& getCollisionType() = 0;
	virtual sf::FloatRect getHitBox();

	void setPosition(sf::Vector2f);

	Entity(); // später löschen
	Entity(sf::Vector2f, sf::Vector2f);
	virtual ~Entity();

	virtual void takeDamage(float);
	virtual void addStatusEffect(StatusEffect );

	virtual void update() = 0;
	virtual void render();

	virtual void pauseEntitiy();
	virtual void continueEntitiy();
};

