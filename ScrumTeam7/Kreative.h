#pragma once
#include "BaseEnemy.h"

class Kreative : public BaseEnemy
{

private:

	static int count;

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

	Kreative(const sf::Vector2f& tilePosition);
	virtual ~Kreative();

	void move();

	void update() override;
};

