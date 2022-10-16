#pragma once

#include "BaseAmmo.h"

class TestAmmo : public BaseAmmo
{
private:
	static float damage;
	static sf::Texture* texture;
	static sf::Vector2f dir;

public:
	static void LoadTexture();
	static void unLoadTexture();

	TestAmmo(sf::Vector2f TowerPosition);
	~TestAmmo();

	void move();

	void update();
	void render();


};

