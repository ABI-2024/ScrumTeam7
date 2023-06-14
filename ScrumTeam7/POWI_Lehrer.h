#pragma once

#include "BaseTower.h"
#include "POWI_Book.h"

class POWI_Lehrer : public BaseTower
{
private:
	static AllyType type;

	static int Cost;

	static float Health;

	static sf::Time bookRespawnTime;
	static sf::Texture* texture;

	POWI_Book book;

public:
	static void LoadTexture();
	static void unLoadTexture();

	POWI_Lehrer(sf::Vector2f tilePosition);
	virtual ~POWI_Lehrer();

	void takeDamage(float) override;

	void update() override;
	void render() override;
};

