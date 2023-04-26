#pragma once

#include "BaseAmmo.h"

class INF_Ammo : public BaseAmmo
{
private:
	static AmmoType ammoType[3];

	static float damage[3];

	static sf::Texture* texture;
	static sf::Vector2f dir;

	AmmoType curendType;

public:
	static void LoadTexture();
	static void unLoadTexture();

	INF_Ammo(sf::Vector2f TowerPosition, AmmoType type);
	~INF_Ammo();


	AmmoType getAmmoType() override;
	float getDamage() override;

	void move();

	void update() override;


};

