#include "TestEnemy.h"

#include <iostream>

// static Variables

int TestEnemy::EnemyType = 1;

float TestEnemy::Health = 200;
float TestEnemy::Damage = 20;

int TestEnemy::revenue = 5;

sf::Vector2f TestEnemy::dir = sf::Vector2f(-0.5, 0);

sf::Texture* TestEnemy::texture = nullptr;

sf::Time TestEnemy::attackSpeed = sf::seconds(3);


// static Methoden
void TestEnemy::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();
	}

	if (!texture->loadFromFile("Textures/DefaultTexture.png")) {
		std::cout << "\tFail: Textur not loaded!\n\n";
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
	this->initBaseVariables(EnemyType, Damage, Health, linePosition, texture);
}

TestEnemy::~TestEnemy()
{
}

int TestEnemy::getRevenue() {
	return revenue;
}

bool TestEnemy::CollisionWithTower(sf::FloatRect& Tower)
{
	return sf::FloatRect(this->Body.getGlobalBounds()).intersects(Tower);
}

void TestEnemy::move()
{
	this->Body.move(this->dir);
}

void TestEnemy::update()
{
	if (this->attackSpeed >= this->clock.getElapsedTime()) {
		ReadyToAttack = true;
	}
	this->move();
}


// public Methoden

