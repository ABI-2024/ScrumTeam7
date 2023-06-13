#pragma once

#include "BaseTower.h"

class Mathelehrer : public BaseTower
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

	Mathelehrer(sf::Vector2f tilePosition);
	virtual ~Mathelehrer();

	void takeDamage(float) override;

	void update() override;

};

