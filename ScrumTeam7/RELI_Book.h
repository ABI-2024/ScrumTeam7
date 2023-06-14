#pragma once

#include "SFML/Graphics.hpp"

class RELI_Book
{
private:

	static sf::Texture* texture;

	bool alive;
	float health;
	sf::RectangleShape body;

public:
	static void LoadTexture();
	static void unLoadTexture();

	RELI_Book(sf::Vector2f position);
	~RELI_Book();

	bool isAlive();

	void reset();

	void takeDamage(const float& damage);
	void heal(const float& heal);

	void render();
};

