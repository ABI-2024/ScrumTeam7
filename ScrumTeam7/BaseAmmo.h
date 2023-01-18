#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "enums.h"



class BaseAmmo
{
public:
	static std::vector<BaseAmmo*> Ammos;

protected:

	bool hit;

	sf::RectangleShape Body;

public:
	BaseAmmo(sf::Vector2f TowerPosition, sf::Texture* texture);
	~BaseAmmo();

	bool isHit();

	virtual AmmoType getAmmoType() = 0;
	virtual float getDamage() = 0;

	void hasHit();

	virtual bool CollisionWithEnemy(sf::FloatRect& Enemy) = 0;

	virtual void update() = 0;
	void render();
};


