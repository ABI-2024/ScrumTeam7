#include "Emo.h"
#include "Window.h"
#include "BaseTower.h"
#include "AActors.h"
#include <iostream>

// static Variables

EnemyType Emo::enemyType = EnemyType::Emo;

float Emo::Health = 1000;
float Emo::Damage = 40;
float Emo::SelfharmDMG = 20;

int Emo::revenue = 0;

sf::Vector2f Emo::dir = sf::Vector2f(-20, 0);

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
}

Emo::~Emo() {
	male->play();

}

// public get-Methoden

// public Methoden
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

	updateStatusprocs(true, true);

	Entity* temp = AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::ally);

	if (temp != nullptr && status.canAttack) {	//True wenn es mit einem Lehrer kollidiert
		movable = false;
		if (clock.getElapsedTime() + this->remainingAttackTime >= this->attackSpeed) {
			temp->takeDamage(this->Damage);
			this->takeDamage(this->SelfharmDMG);

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