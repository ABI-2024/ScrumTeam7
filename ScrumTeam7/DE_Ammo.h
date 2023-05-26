#pragma once
#include "BaseAmmo.h"

class DE_Ammo : public BaseAmmo
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

	DE_Ammo(sf::Vector2f TowerPosition);
	~DE_Ammo();

	AmmoType getAmmoType() override;
	float getDamage() override;

	void update() override;


};

