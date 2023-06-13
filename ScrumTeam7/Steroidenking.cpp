#include "Steroidenking.h"

#include "Window.h"
#include "Randomizer.h"

#include "AActors.h"

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
}

Steroidenking::~Steroidenking() 
{
	AActors::addCollectedRevenue(this->revenue);
}

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

	updateStatusprocs(true, true);

	int type = 0;
	if (running) {
		type = 1;
	}
	Entity* temp = AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::ally);

	if (temp != nullptr && status.canAttack) {	//True wenn es mit einem Lehrer kollidiert
		running = false;
		movable = false;
		if (clock.getElapsedTime() + this->remainingAttackTime >= this->attackSpeed) {

			temp->takeDamage(this->Damage[type]);

			this->remainingAttackTime = sf::seconds(0);
			clock.restart();
		}
	}
	else {
		movable = true;
	}

	if (status.canWalk) {
		this->move();
	}

	if (!status.alive) {
		AActors::destroy(this);
	}
}



