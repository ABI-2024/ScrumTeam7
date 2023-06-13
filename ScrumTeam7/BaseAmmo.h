#pragma once

#include "Entity.h"

#include "enums.h"



class BaseAmmo : public Entity
{
protected:

public:
	BaseAmmo(const sf::Vector2f& TowerPosition, sf::Texture * texture); // texture nicht hier setzten
	virtual ~BaseAmmo();

	const CollisionType& getCollisionType() override;
		
	virtual AmmoType getAmmoType() = 0;
	virtual float getDamage() = 0;

	virtual void update() = 0;
	void renderShadow() override;
};


