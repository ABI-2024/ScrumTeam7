#pragma once

#include "BaseTower.h"

class TestTower : public BaseTower
{
private:
	static AllyType type;

	static int Cost;

	static float Health;

	static sf::Time fireRate;
	static sf::Time maximumFireRateDiviation;
	static sf::Texture* texture;

public:
	static void LoadTexture();
	static void unLoadTexture();

	TestTower(sf::Vector2f tilePosition);
	~TestTower();
	
	void update() override;
};
