#pragma once

#include "BaseTower.h"

class INF_Lehrer : public BaseTower
{
private:
	static TowerType towerType;
	static AmmoType ammoType[3];

	static int Cost;

	static float Health;

	static sf::Time fireRate;
	static sf::Time maximumFireRateDiviation;
	static sf::Texture* texture;

	AmmoType nextShot;
	char powerup;
	enum class PowerLevel : char	{
		OnlyMouse = 1,
		MouseKeyboard,
		OnlyKeyboard,
		KeyboardMonitor,
		OnlyMonitor
	} level;

public:
	static void LoadTexture();
	static void unLoadTexture();

	INF_Lehrer(sf::Vector2f tilePosition);
	~INF_Lehrer();

	TowerType getTowerType() override;
	AmmoType getAmmoType() override;

	void HasAttacked() override;
	void update() override;
};

