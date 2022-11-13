#pragma once

#include "BaseEnemy.h"

class TestEnemy : public BaseEnemy
{
private:
	static int EnemyType;

	static float Health;
	static float Damage;

	static sf::Vector2f dir;
	static sf::Texture* texture;

	static sf::Time attackSpeed;

public:
	static void LoadTexture();
	static void unLoadTexture();

	TestEnemy();
	TestEnemy(float linePosition);

	~TestEnemy();

	bool CollisionWithTower(sf::FloatRect& Tower) override;

	void move();

	void update() override;
};

