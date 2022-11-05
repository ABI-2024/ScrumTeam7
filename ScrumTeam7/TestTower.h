#pragma once

#include "BaseTower.h"

class TestTower : public BaseTower
{
private:
	static int TowerType;
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

	void update() override;
};
