#include "Nerd.h"
#include "Window.h"

#include <iostream>

// static Variables

EnemyType Nerd::enemyType = EnemyType::Nerd;

float Nerd::Health = 200;
float Nerd::Damage = 20;

int Nerd::revenue = 8;

sf::Vector2f Nerd::dir = sf::Vector2f(-7, 0);

sf::Texture* Nerd::texture = nullptr;

sf::Time Nerd::attackSpeed = sf::milliseconds(750);


// public static Methoden
void Nerd::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/StandartSchüler.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Nerd::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Nerd::Nerd(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health, tilePosition, texture)
{}

Nerd::~Nerd() {}

// public get-Methoden
int Nerd::getRevenue() {
	return revenue;
}

EnemyType Nerd::getEnemyType()
{
	return this->enemyType;
}

float Nerd::getDamage()
{
	return this->Damage;
}

// public Methoden
bool Nerd::CollisionWithTower(sf::FloatRect& Tower)
{
	if (sf::FloatRect(this->body.getGlobalBounds()).intersects(Tower)) {
		movable = false;
		return 1;
	}
	else {
		return 0;
	}
}

void Nerd::move()
{
	if (movable) {
		this->body.move(this->dir * dt);
	}
	else {
		movable = true;
	}
}

void Nerd::update()
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
