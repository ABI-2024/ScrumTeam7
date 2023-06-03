#include "Nerd.h"
#include "Window.h"
#include "AActors.h"

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

		if (!texture->loadFromFile("resource/Textures/Schueler/Nerd.png")) {
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
{
	
}

Nerd::~Nerd() 
{
	AActors::addCollectedRevenue(this->revenue);
}

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

	this->updateStatus_Proc();

	Entity* temp = AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::ally);

	if (temp != nullptr) {
		movable = false;
		if (clock.getElapsedTime() + this->remainingAttackTime >= this->attackSpeed) {
			temp->takeDamage(this->Damage);

			this->remainingAttackTime = sf::seconds(0);
			clock.restart();
		}
	}
	else {
		movable = true;
	}

	this->move();

	if (!alive) {
		AActors::destroy(this);
	}
}
