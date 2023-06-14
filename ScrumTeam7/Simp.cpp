#include "Simp.h"
#include "Window.h"
#include "BaseTower.h"
#include "AActors.h"
#include <iostream>

// static Variables

EnemyType Simp::enemyType = EnemyType::Simp;

float Simp::Health = 400;
float Simp::Damage = 0;

int Simp::revenue = 5;

sf::Vector2f Simp::dir = sf::Vector2f(-15, 0);

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

Simp::~Simp() {
	male->play();
}

// public get-Methoden
// public Methoden
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

	updateStatusprocs(true, true);

	Entity* temp = AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::ally);

	if (temp != nullptr && status.canAttack) {	//True wenn es mit einem Lehrer kollidiert
		movable = false;
		if (clock.getElapsedTime() + this->remainingAttackTime >= this->attackSpeed) {
			temp->addStatusEffect(StatusEffect(StatusType::cripple, sf::seconds(0.75), 0));

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
