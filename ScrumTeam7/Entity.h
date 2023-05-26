#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "enums.h"

enum class CollisionType : char {
	non = 0,

	ally,
	allyAmmo,

	enemies
};

class Entity
{
protected:

	bool alive;

	static sf::Texture* shadowTexture;

	sf::RectangleShape body;
	sf::RectangleShape shadow;

public:
	static void loadTexture();
	static void unloadTexture();

	virtual void renderShadow();
	
	virtual const CollisionType& getCollisionType(); // sp�ter l�schen
	//virtual const CollisionType& getCollisionType() = 0; // echte
	virtual sf::FloatRect getHitBox();

	Entity(); // sp�ter l�schen
	Entity(sf::Vector2f, sf::Vector2f);
	virtual ~Entity();


	virtual void update() = 0;
	virtual void render();

};

