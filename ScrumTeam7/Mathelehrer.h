#pragma once

#include "BaseTower.h"

class Mathelehrer : public BaseTower
{
private:
	static TowerType towerType;
	static AmmoType ammoType;

	static int Cost;

	static float Health;

	static sf::Time fireRate;
	static sf::Time maximumFireRateDiviation;
	static sf::Texture* texture;

	static int accuracy, countVertex;
	static sf::Vertex* sinusLine;
public:
	static void LoadTexture();
	static void unLoadTexture();

	Mathelehrer(sf::Vector2f tilePosition);
	~Mathelehrer();

	TowerType getTowerType() override;
	AmmoType getAmmoType() override;

	void HasAttacked() override;
	void update() override;

};

