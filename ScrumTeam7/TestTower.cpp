#include "TestTower.h"

#include "Randomizer.h"
#include "AActors.h"

// public static Variables 
AllyType TestTower::type;


// private static Variables 
int TestTower::Cost = 20;
float TestTower::Health = 200;
sf::Time TestTower::fireRate = sf::milliseconds(1500);
sf::Time TestTower::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* TestTower::texture = nullptr;


// public static Methoden
void TestTower::LoadTexture()
{	
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/SP/SP-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
	
}

void TestTower::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
TestTower::TestTower(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture) 
{}

TestTower::~TestTower()
{
}


//public Methoden
void TestTower::takeDamage(float damage) {
	health -= damage;
	if (health <= 0) {
		alive = false;
	}
}

void TestTower::update()
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

	if (clock.getElapsedTime()+ this->remainingAttackTime >= fireRate+ fireRateDiviation && enemyOnLines[(int)tilePosition.y]) {
		AActors::create(AmmoType::TestAmmo, this->body.getPosition());
		
		fireRateDiviation = sf::milliseconds( maximumFireRateDiviation.asMilliseconds() / Randomizer::randomize(9, 1) );
		this->remainingAttackTime = sf::seconds(0);
		clock.restart();
	}

	if (!alive) {
		AActors::destroy(this);
	}
}

