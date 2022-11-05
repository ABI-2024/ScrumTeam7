#pragma once

#include "SFML/Graphics.hpp"



class BaseAmmo
{
protected:
	int AmmoType;

	bool hit;
	float damage;

	sf::RectangleShape Body;

	void initBaseVariables(int ammoType, float damage , sf::Vector2f TowerPosition, sf::Texture* texture);
public:
	BaseAmmo();
	~BaseAmmo();

	bool isHit();
	int getType();
	float getDamage();

	void hasHit();

	virtual bool CollisionWithEnemy(sf::FloatRect& Enemy) = 0;

	virtual void update() = 0;
	void render();
};


