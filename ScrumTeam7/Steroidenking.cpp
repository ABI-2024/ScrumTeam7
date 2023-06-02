#include "Steroidenking.h"

#include "Window.h"
#include "Randomizer.h"

// static Variables

EnemyType Steroidenking::enemyType = EnemyType::Steroidenking;

float Steroidenking::Health = 200;
float Steroidenking::Damage[2] = { 30,100 };

int Steroidenking::revenue = 15;

sf::Vector2f Steroidenking::dir[2] = { sf::Vector2f(-10, 0),sf::Vector2f(-40, 0) };

sf::Texture* Steroidenking::texture = nullptr;

sf::Time Steroidenking::attackSpeed = sf::milliseconds(1400);


// public static Methoden
void Steroidenking::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Schueler/Steroidenking.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Steroidenking::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Steroidenking::Steroidenking(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health, tilePosition, texture), running(true)
{ 
	readyToAttack = true;
}

Steroidenking::~Steroidenking() {}

// public get-Methoden
int Steroidenking::getRevenue() {
	return revenue;
}

EnemyType Steroidenking::getEnemyType()
{
	return this->enemyType;
}

float Steroidenking::getDamage()
{
	int type = 0;

	if (running) {
		type = 1;
		running = false;
	}

	return this->Damage[type];
}

// public Methoden
bool Steroidenking::CollisionWithTower(sf::FloatRect& Tower)
{
	if (sf::FloatRect(this->body.getGlobalBounds()).intersects(Tower)) {
		movable = false;
		return 1;
	}
	else {
		return 0;
	}
}

void Steroidenking::move()
{
	int type = 0;
	if (running) {
		type = 1;
	}

	if (movable) {
		this->body.move(this->dir[type] * dt);
	}
	else {
		movable = true;
	}
}

void Steroidenking::update()
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



