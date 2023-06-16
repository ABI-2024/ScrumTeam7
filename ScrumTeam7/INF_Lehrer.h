#pragma once

#include "BaseTower.h"

class INF_Lehrer : public BaseTower
{
private:
	static AllyType type;

	static int Cost;

	static float Health;

	static sf::Time fireRate;
	static sf::Time maximumFireRateDiviation;
	static sf::Texture* texture;

	static sf::Font* font;

	sf::Text ipp;
	sf::Clock animationTimer;
	static sf::Time animationTime;

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
	virtual ~INF_Lehrer();

	void takeDamage(float) override;

	void update() override;
	void render() override;
};

