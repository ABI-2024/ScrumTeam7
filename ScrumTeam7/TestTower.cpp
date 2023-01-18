#include "TestTower.h"

#include <iostream>


// static Variablen
TowerType TestTower::towerType = TowerType::TestTower;
int TestTower::Cost = 20;
float TestTower::Health = 200;
sf::Time TestTower::fireRate = sf::milliseconds(1500);
sf::Texture* TestTower::texture = nullptr;

// static Methoden
void TestTower::LoadTexture()
{	
	if (texture == nullptr) {
		texture = new sf::Texture();
	}

	if (!texture->loadFromFile("resource/Textures/SportLehre1.png")) {
		std::cout << "\tFail: Textur not loaded!\n\n";

		if (!texture->loadFromFile("resource/Textures/DefaultTexture.png")) {
			std::cout << "\tFail: Textur not loaded!\n\n";
		}
	}
	
}

void TestTower::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}

// private Methden

<<<<<<< HEAD
// Constructur & Destructur
=======
// Konstructur & Destructur
TestTower::TestTower()
{
}

>>>>>>> fc63e980b9a27a7aaf4aeac33d13143d9658ea77
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

//public Methoden


void TestTower::update()
{
	if (this->fireRate <= this->clock.getElapsedTime() + this->remainingAttackTime) {
		this->ReadyToAttack = true;
	}
}

