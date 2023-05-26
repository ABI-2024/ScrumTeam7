#pragma once
#include "BaseTower.h"

class DE_Lehrer : public BaseTower
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

	DE_Lehrer(sf::Vector2f tilePosition);
	~DE_Lehrer();

	void update() override;
};

