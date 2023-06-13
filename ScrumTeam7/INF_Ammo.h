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
	float getDamage();
public:
	static void LoadTexture();
	static void unLoadTexture();

	INF_Ammo(sf::Vector2f TowerPosition, AmmoType type);
	virtual ~INF_Ammo();

	void move();

	void update() override;


};

