#pragma once

#include "enums.h"
#include "SFML/Graphics.hpp"



class BaseAmmo
{
protected:

	bool hit;

	sf::RectangleShape Body;

	void initBaseVariables( sf::Vector2f TowerPosition, sf::Texture* texture);
public:
	BaseAmmo();
	~BaseAmmo();

	bool isHit();

	virtual AmmoType getAmmoType() = 0;
	virtual float getDamage() = 0;

	void hasHit();

	virtual bool CollisionWithEnemy(sf::FloatRect& Enemy) = 0;

	virtual void update() = 0;
	void render();
};


