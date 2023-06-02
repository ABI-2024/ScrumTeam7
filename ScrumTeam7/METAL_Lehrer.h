#pragma once
#include "BaseTower.h"

class METAL_Lehrer : public BaseTower
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

	METAL_Lehrer(sf::Vector2f tilePosition);
	~METAL_Lehrer();

	void takeDamage(float) override;

	void update() override;
};

