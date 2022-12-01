#pragma once

#include "BaseEnemy.h"

class TestEnemy : public BaseEnemy
{
private:
	static EnemyType enemyType;

	static float Health;
	static float Damage;

	static int revenue;

	static sf::Vector2f dir;
	static sf::Texture* texture;

	static sf::Time attackSpeed;

public:
	static void LoadTexture();
	static void unLoadTexture();

	TestEnemy();
	TestEnemy(float linePosition);

	~TestEnemy();

	static int getRevenue();


	EnemyType getEnemyType() override;
	float getDamage() override;

	bool CollisionWithTower(sf::FloatRect& Tower) override;

	void move();

	void update() override;
};

