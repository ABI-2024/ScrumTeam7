#include "TestTower.h"
#include "SFML/Config.hpp"

// public static Variables 
TowerType TestTower::towerType = TowerType::TestTower;


// private static Variables 
int TestTower::Cost = 20;
float TestTower::Health = 200;
sf::Time TestTower::fireRate = sf::milliseconds(1500);
sf::Time TestTower::maximumFireRateDiviation = sf::milliseconds(100);
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
}

//public Methoden
void TestTower::update()
{
	if (this->fireRate <= this->clock.getElapsedTime() + this->remainingAttackTime) {
		this->readyToAttack = true;
	}
}

