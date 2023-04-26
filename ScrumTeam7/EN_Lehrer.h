#pragma once
#include "BaseTower.h"

class EN_Lehrer : public BaseTower
{
private:
	static TowerType towerType;
	static AmmoType ammoType[4];

	static int Cost;

	static float Health;

	static sf::Time fireRate;
	static sf::Time maximumFireRateDiviation;
	static sf::Texture* texture;

public:
	static void LoadTexture();
	static void unLoadTexture();

	EN_Lehrer(sf::Vector2f tilePosition);
	~EN_Lehrer();

	TowerType getTowerType() override;
	AmmoType getAmmoType() override;

	void HasAttacked() override;
	void update() override;
};



