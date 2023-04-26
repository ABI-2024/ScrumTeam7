#pragma once

#include "BaseAmmo.h"

class MA_Ammo : public BaseAmmo
{
private:
	static AmmoType ammoType;

	static float damage;

	static sf::Texture* texture;
	static sf::Vector2f dir;

	sf::Vector2f offset; //offset der Sinus Funktion

public:
	static void LoadTexture();
	static void unLoadTexture();

	MA_Ammo(sf::Vector2f TowerPosition);
	~MA_Ammo();


	AmmoType getAmmoType() override;
	float getDamage() override;

	void move();

	void update() override;


};

