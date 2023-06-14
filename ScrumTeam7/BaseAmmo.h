#pragma once

#include "Entity.h"

#include "enums.h"
#include "SFML/Audio.hpp"



class BaseAmmo : public Entity
{
protected:

	static sf::SoundBuffer* buffer;
	static sf::Sound* hitSound;

public:
	static void loadSound();
	static void unloadSound();

	BaseAmmo(const sf::Vector2f& TowerPosition, sf::Texture * texture); // texture nicht hier setzten
	virtual ~BaseAmmo();

	const CollisionType& getCollisionType() override;

	virtual void update() = 0;
	void renderShadow() override;
};


