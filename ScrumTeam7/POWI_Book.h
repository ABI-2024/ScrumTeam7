#pragma once

#include "SFML/Graphics.hpp"

class POWI_Book
{
private:

	static sf::Texture* texture;

	bool alive;
	float health;
	float revenue;
	sf::RectangleShape body;


	static sf::Font* font;

	sf::Text stongs;
	sf::Clock animationTimer;
	static sf::Time animationTime;

public:
	static void LoadTexture();
	static void unLoadTexture();

	POWI_Book(sf::Vector2f position);
	~POWI_Book();

	bool isAlive();

	void reset();

	void takeDamage(const float& damage);
	void heal(const float& heal);

	void render();
};

