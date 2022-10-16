#pragma once

#include "BaseEnemy.h"

class TestEnemy : public BaseEnemy
{
private:
	static float EnemyHealth;
	static float damage;

	static sf::Vector2f dir;
	static sf::Texture* texture;

	static sf::Time attackSpeed;

	void initVariables(float linePosition);
public:
	static void LoadTexture();
	static void unLoadTexture();

	TestEnemy();
	TestEnemy(float linePosition);

	~TestEnemy();

	void move();

	void update();
	void render();
};

