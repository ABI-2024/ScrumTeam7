#pragma once

#include "BaseTower.h"

class TestTower : public BaseTower
{
private:
	static TowerType towerType;
	static int Cost;

	static float Health;

	static sf::Time fireRate;
	static sf::Texture* texture;

public:
	static void LoadTexture();
	static void unLoadTexture();

	TestTower();
	TestTower(sf::Vector2f tilePosition);

	~TestTower();

	TowerType getTowerType() override;

	void update() override;
};
