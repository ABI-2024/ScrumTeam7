#pragma once

#include "BaseAmmo.h"

class TestAmmo : public BaseAmmo
{
private:
	static AmmoType ammoType;

	static float damage;

	static sf::Texture* texture;
	static sf::Vector2f dir;

public:
	static void LoadTexture();
	static void unLoadTexture();

	TestAmmo(sf::Vector2f TowerPosition);
	virtual ~TestAmmo();


	AmmoType getAmmoType() override;
	float getDamage() override;

	void move();

	void update() override;


};

