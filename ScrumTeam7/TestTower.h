#pragma once
#include "BaseTower.h"

class TestTower : public BaseTower
{
private:
	static int towerCost;
	static float towerHealth;
	static sf::Time fireRate;
	static sf::Texture* texture;

	std::vector<TestAmmo*> ammo;


	void initVariables(sf::Vector2f tilePosition);
public:
	static void LoadTexture();
	static void unLoadTexture();

	TestTower();
	TestTower(sf::Vector2f tilePosition);

	~TestTower();

	void shoot();
	void ammoDelete();

	void update();
	void render();


};
