#include "Kreative.h"

#include "Window.h"
#include "AActors.h"

#include <math.h>

// static Variables
int Kreative::count = 0;

EnemyType Kreative::enemyType = EnemyType::Kreative;

float Kreative::Health = 200;
float Kreative::Damage = 20;

int Kreative::revenue = 8;

sf::Vector2f Kreative::dir = sf::Vector2f(-25, 0);

sf::Texture* Kreative::texture = nullptr;

sf::Time Kreative::attackSpeed = sf::milliseconds(750);


// public static Methoden
void Kreative::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Schueler/Kreative.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Kreative::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Kreative::Kreative(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health*(float)sqrt(count+1), tilePosition, texture)
{
	count++;
}

Kreative::~Kreative()
{
	count--;
	AActors::addCollectedRevenue(this->revenue);
	female->play();
}

// public Methoden

void Kreative::move()
{
	if (movable) {
		this->body.move(this->dir * dt);
	}
	else {
		movable = true;
	}
}

void Kreative::update()
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

	Entity* temp = AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::ally);

	if (temp != nullptr && status.canAttack) {
		movable = false;
		if (clock.getElapsedTime() + this->remainingAttackTime >= this->attackSpeed) {
			temp->takeDamage(this->Damage * (float)sqrt(count));

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

