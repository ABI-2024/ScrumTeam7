#include "Simp.h"
#include "Window.h"
#include "BaseTower.h"

#include <iostream>

// static Variables

EnemyType Simp::enemyType = EnemyType::Simp;

float Simp::Health = 100;
float Simp::Damage = 0;

int Simp::revenue = 8;

sf::Vector2f Simp::dir = sf::Vector2f(-7, 0);

sf::Texture* Simp::texture = nullptr;

sf::Time Simp::attackSpeed = sf::milliseconds(750);


// public static Methoden
void Simp::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Schueler/Simp.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Simp::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Simp::Simp(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health, tilePosition, texture)

{
	programmzeit.restart();
}

Simp::~Simp() {}

// public get-Methoden
int Simp::getRevenue() {
	return revenue;
}

EnemyType Simp::getEnemyType()
{
	return this->enemyType;
}

float Simp::getDamage()
{
	return this->Damage;
}

// public Methoden
bool Simp::CollisionWithTower(sf::FloatRect& Tower)
{
	if (sf::FloatRect(this->body.getGlobalBounds()).intersects(Tower)) {
		movable = false;
		return 1;
	}
	else {
		return 0;
	}
}

void Simp::move()
{
	if (movable) {
		this->body.move(this->dir * dt);
	}
	else {
		movable = true;
	}
}

void Simp::update()
{
	if (health <= Health / 5) {
		body.setFillColor({ 139,0,0 }); //DarkRed
	}
	else if (health <= Health / 2) {
		body.setFillColor({ 255,48,48 }); //firebrick1

	}
	else if (health <= Health * 0.8) {
		body.setFillColor({ 255,99,71 }); //tomato1
	}

	if (this->attackSpeed <= this->clock.getElapsedTime()) {
		readyToAttack = true;
	}

	this->updateStatus_Proc();

	this->move();
}
