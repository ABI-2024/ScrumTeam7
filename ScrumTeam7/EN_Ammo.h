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


	float getDamage();

public:
	static void LoadTexture();
	static void unLoadTexture();

	EN_Ammo(sf::Vector2f TowerPosition, AmmoType type);
	virtual ~EN_Ammo();


	void move();

	void update() override;


};



