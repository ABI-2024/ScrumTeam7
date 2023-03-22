#include "TestTower.h"
#include "Randomizer.h"

// public static Variables 
TowerType TestTower::towerType = TowerType::TestTower;


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

		if (!texture->loadFromFile("resource/Textures/SportLehre1.png")) {
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
	if (this->fireRate + this->fireRateDiviation <= this->clock.getElapsedTime() + this->remainingAttackTime) {
		this->readyToAttack = true;
	}
}

