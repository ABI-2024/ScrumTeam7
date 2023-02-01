#include "TestEnemy.h"
#include "Window.h"

#include <iostream>

// static Variables

EnemyType TestEnemy::enemyType = EnemyType::TestEnemy;

float TestEnemy::Health = 200;
float TestEnemy::Damage = 20;

int TestEnemy::revenue = 5;

sf::Vector2f TestEnemy::dir = sf::Vector2f(-10, 0);

sf::Texture* TestEnemy::texture = nullptr;

sf::Time TestEnemy::attackSpeed = sf::milliseconds(750);


// public static Methoden
void TestEnemy::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/StandartSchüler.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void TestEnemy::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
TestEnemy::TestEnemy(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health, tilePosition, texture)
{}

TestEnemy::~TestEnemy() {}

// public get-Methoden
int TestEnemy::getRevenue() {
	return revenue;
}

EnemyType TestEnemy::getEnemyType()
{
	return this->enemyType;
}

float TestEnemy::getDamage()
{
	return this->Damage;
}

// public Methoden
bool TestEnemy::CollisionWithTower(sf::FloatRect& Tower)
{
	if (sf::FloatRect(this->body.getGlobalBounds()).intersects(Tower)) {
		movable = false;
		return 1;
	}
	else {
		return 0;
	}
}

void TestEnemy::move()
{
	if (movable) {
		this->body.move(this->dir * dt);
	}
	else {
		movable = true;
	}
}

void TestEnemy::update()
{
	if (health<= Health/5 ) {
		body.setFillColor({ 255,0,0 });
	}
	else if (health <= Health/2) {
		body.setFillColor({ 127,32,32 });

	}

	if (this->attackSpeed <= this->clock.getElapsedTime()) {
		readyToAttack = true;
	}
	this->move();
}



