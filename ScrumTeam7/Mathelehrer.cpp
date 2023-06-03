#include "Mathelehrer.h"
#include "Randomizer.h"
#include "Window.h"
#include "AActors.h"

#include <math.h>

// public static Variables 
AllyType Mathelehrer::type;


// private static Variables 
int Mathelehrer::Cost = 20;
float Mathelehrer::Health = 200;
sf::Time Mathelehrer::fireRate = sf::milliseconds(2000);
sf::Time Mathelehrer::maximumFireRateDiviation = sf::milliseconds(400);
sf::Texture* Mathelehrer::texture = nullptr;

// public static Methoden
void Mathelehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/MA/MA-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Mathelehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Mathelehrer::Mathelehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture)
{}

Mathelehrer::~Mathelehrer()
{
}

//public Methoden
void Mathelehrer::takeDamage(float damage) {
	health -= damage;
	if (health <= 0) {
		alive = false;
	}
}

void Mathelehrer::update()
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

	if (clock.getElapsedTime() + this->remainingAttackTime >= fireRate + fireRateDiviation && enemyOnLines[(int)tilePosition.y]) {
		AActors::create(AmmoType::Mathe, this->body.getPosition());

		fireRateDiviation = sf::milliseconds(maximumFireRateDiviation.asMilliseconds() / Randomizer::randomize(9, 1));
		this->remainingAttackTime = sf::seconds(0);
		clock.restart();
	}

	if (!alive) {
		AActors::destroy(this);
	}
}


