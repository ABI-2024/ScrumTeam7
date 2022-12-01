#include "TestEnemy.h"

#include <iostream>

// static Variables

EnemyType TestEnemy::enemyType = EnemyType::TestEnemy;

float TestEnemy::Health = 200;
float TestEnemy::Damage = 20;

int TestEnemy::revenue = 5;

sf::Vector2f TestEnemy::dir = sf::Vector2f(-1, 0);

sf::Texture* TestEnemy::texture = nullptr;

sf::Time TestEnemy::attackSpeed = sf::milliseconds(750);


// static Methoden
void TestEnemy::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();
	}

	if (!texture->loadFromFile("resource/Textures/StandartSchüler.png")) {
		std::cout << "\tFail: Textur not loaded!\n\n";

		if (!texture->loadFromFile("resource/Textures/DefaultTexture.png")) {
			std::cout << "\tFail: Textur not loaded!\n\n";
		}
	}

}

void TestEnemy::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
TestEnemy::TestEnemy()
{
}

TestEnemy::TestEnemy(float linePosition)
{
	this->initBaseVariables( Health, linePosition, texture);
}

TestEnemy::~TestEnemy()
{
}

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

bool TestEnemy::CollisionWithTower(sf::FloatRect& Tower)
{
	if (sf::FloatRect(this->Body.getGlobalBounds()).intersects(Tower)) {
		Movable = false;
		return 1;
	}
	else {
		return 0;
	}
}

void TestEnemy::move()
{
	if (Movable) {
		this->Body.move(this->dir);
	}
	else {
		Movable = true;
	}
}

void TestEnemy::update()
{
	if (health<= Health/5 ) {
		Body.setFillColor({ 255,0,0 });
	}
	else if (health <= Health/2) {
		Body.setFillColor({ 127,32,32 });

	}

	if (this->attackSpeed <= this->clock.getElapsedTime()) {
		ReadyToAttack = true;
	}
	this->move();
}


// public Methoden

