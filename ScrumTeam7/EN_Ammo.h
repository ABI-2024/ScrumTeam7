#pragma once

#include "BaseAmmo.h"

class EN_Ammo : public BaseAmmo
{
private:
	static AmmoType ammoType[4];

	static float damage[4];

	static sf::Texture* texture;
	static sf::Vector2f dir;

	AmmoType curendType;

public:
	static void LoadTexture();
	static void unLoadTexture();

	EN_Ammo(sf::Vector2f TowerPosition, AmmoType type);
	~EN_Ammo();


	AmmoType getAmmoType() override;
	float getDamage() override;

	void move();

	void update() override;


};



