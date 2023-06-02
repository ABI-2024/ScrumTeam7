#include "METAL_Lehrer.h"

#include "Randomizer.h"

// public static Variables 
TowerType METAL_Lehrer::towerType = TowerType::METAL_Lehrer;
AmmoType METAL_Lehrer::ammoType = AmmoType::METAL_Ammo;


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

TowerType METAL_Lehrer::getTowerType()
{
	return this->towerType;
}

AmmoType METAL_Lehrer::getAmmoType() {
	return this->ammoType;
}

void METAL_Lehrer::HasAttacked()
{
	this->readyToAttack = false;
	this->clock.restart();
	this->remainingAttackTime = sf::milliseconds(0);
	this->fireRateDiviation = sf::milliseconds(Randomizer::randomize((int)this->maximumFireRateDiviation.asMilliseconds() * 2, -(int)this->maximumFireRateDiviation.asMilliseconds()));
}

//public Methoden
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

	if (this->fireRate + this->fireRateDiviation <= this->clock.getElapsedTime() + this->remainingAttackTime) {
		this->readyToAttack = true;
	}
}
