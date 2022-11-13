#pragma once

#include "BaseAmmo.h"

class TestAmmo : public BaseAmmo
{
private:
	static int ammoType;

	static float damage;

	static sf::Texture* texture;
	static sf::Vector2f dir;

public:
	static void LoadTexture();
	static void unLoadTexture();

	TestAmmo(sf::Vector2f TowerPosition);
	~TestAmmo();



	bool CollisionWithEnemy(sf::FloatRect& Enemy) override;

	void move();

	void update() override;


};

