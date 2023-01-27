#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

class Entity
{
public:
	static std::vector<Entity*> entities;

protected:
	static sf::Texture* shadowTexture;

	sf::RectangleShape body;
	sf::RectangleShape shadow;

	Entity();
	~Entity();
public:
	static void loadTexture();
	static void unloadTexture();

	void renderShadow();
};

