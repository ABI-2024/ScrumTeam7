#include "METAL_Lehrer.h"

#include "Randomizer.h"
#include "AActors.h"

// public static Variables 
AllyType METAL_Lehrer::type;


// private static Variables 
int METAL_Lehrer::Cost = 20;
float METAL_Lehrer::Health = 200;
sf::Time METAL_Lehrer::fireRate = sf::milliseconds(1500);
sf::Time METAL_Lehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* METAL_Lehrer::texture = nullptr;


// public static Methoden
void METAL_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/METAL/METAL-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

}

void METAL_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
METAL_Lehrer::METAL_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture)
{}

METAL_Lehrer::~METAL_Lehrer()
{
}

//public Methoden
void METAL_Lehrer::takeDamage(float damage) {
	health -= damage;
	if (health <= 0) {
		status.alive = false;
	}
}

void METAL_Lehrer::update()
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
		if (AActors::CollisionSingle(sf::FloatRect(body.getPosition(), { 42.1875f * 48.f / 9.f * 1.5f, 1.f }), CollisionType::enemies) != nullptr) {
			AActors::create(AmmoType::METAL_Ammo, this->body.getPosition());

			fireRateDiviation = sf::milliseconds(maximumFireRateDiviation.asMilliseconds() / Randomizer::randomize(9, 1));
			this->remainingAttackTime = sf::seconds(0);
			clock.restart();
		}
	}

	if (!status.alive) {
		AActors::destroy(this);
	}
}
