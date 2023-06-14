#pragma once

#include "BaseEnemy.h"

class Steroidenking : public BaseEnemy
{
private:
	static EnemyType enemyType;

	static float Health;
	static float Damage[2];

	static int revenue;

	static sf::Vector2f dir[2];
	static sf::Texture* texture;

	static sf::Time attackSpeed;

	bool running;

	float getDamage();
public:
	static void LoadTexture();
	static void unLoadTexture();

	Steroidenking(const sf::Vector2f& tilePosition);
	virtual ~Steroidenking();

	void move();

	void update() override;



};

