#pragma once

#include "BaseAmmo.h"

class Projectil_Pi : public BaseAmmo
{
private:
	static AmmoType ammoType;

	static float damage;

	static sf::Texture* texture;
	static sf::Vector2f dir;

public:
	static void LoadTexture();
	static void unLoadTexture();

	Projectil_Pi(sf::Vector2f TowerPosition);
	~Projectil_Pi();


	AmmoType getAmmoType() override;
	float getDamage() override;

	bool CollisionWithEnemy(sf::FloatRect& Enemy) override;

	void move();

	void update() override;

};

