#include "Emo.h"
#include "Window.h"
#include "BaseTower.h"

#include <iostream>

// static Variables

EnemyType Emo::enemyType = EnemyType::Emo;

float Emo::Health = 400;
float Emo::Damage = 20;

int Emo::revenue = 8;

sf::Vector2f Emo::dir = sf::Vector2f(-7, 0);

sf::Texture* Emo::texture = nullptr;

sf::Time Emo::attackSpeed = sf::milliseconds(750);


// public static Methoden
void Emo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Schueler/Emo.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Emo::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Emo::Emo(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health, tilePosition, texture)

{
	programmzeit.restart();
}

Emo::~Emo() {}

// public get-Methoden
int Emo::getRevenue() {
	return revenue;
}

EnemyType Emo::getEnemyType()
{
	return this->enemyType;
}

float Emo::getDamage()
{
	return this->Damage;
}

// public Methoden
bool Emo::CollisionWithTower(sf::FloatRect& Tower)
{
	if (sf::FloatRect(this->body.getGlobalBounds()).intersects(Tower)) {
		movable = false;
		return 1;
	}
	else {
		return 0;
	}
}

void Emo::move()
{
	if (movable) {
		this->body.move(this->dir * dt);
	}
	else {
		movable = true;
	}
}

void Emo::update()
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
