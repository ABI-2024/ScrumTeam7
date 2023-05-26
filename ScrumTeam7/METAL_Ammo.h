#pragma once

#include "BaseAmmo.h"

class METAL_Ammo : public BaseAmmo
{
private:
	static AmmoType ammoType;

	static float damage;

	static sf::Texture* texture;

	static sf::Time damageWindowStart, activeTime;

	sf::Clock timer;

public:
	static void LoadTexture();
	static void unLoadTexture();

	METAL_Ammo(sf::Vector2f TowerPosition);
	~METAL_Ammo();

	AmmoType getAmmoType() override;
	float getDamage() override;

	void update() override;


};

