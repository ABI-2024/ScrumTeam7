#include "TestTower.h"
#include "Randomizer.h"

// public static Variables 
TowerType TestTower::towerType = TowerType::TestTower;
AmmoType TestTower::ammoType = AmmoType::TestAmmo;


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

TowerType TestTower::getTowerType()
{
	return this->towerType;
}

AmmoType TestTower::getAmmoType() {
	return this->ammoType;
}

void TestTower::HasAttacked()
{
	this->readyToAttack = false;
	this->clock.restart();
	this->remainingAttackTime = sf::milliseconds(0);
	this->fireRateDiviation = sf::milliseconds(Randomizer::randomize( (int)this->maximumFireRateDiviation.asMilliseconds()*2 , -(int)this->maximumFireRateDiviation.asMilliseconds()) );
}

//public Methoden
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

	if (this->fireRate + this->fireRateDiviation <= this->clock.getElapsedTime() + this->remainingAttackTime) {
		this->readyToAttack = true;
	}
}

