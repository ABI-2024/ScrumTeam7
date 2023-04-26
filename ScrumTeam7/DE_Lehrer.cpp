#include "DE_Lehrer.h"

#include "Randomizer.h"

// public static Variables 
TowerType DE_Lehrer::towerType = TowerType::DE_Lehrer;
AmmoType DE_Lehrer::ammoType = AmmoType::DE_Ammo;


// private static Variables 
int DE_Lehrer::Cost = 20;
float DE_Lehrer::Health = 200;
sf::Time DE_Lehrer::fireRate = sf::milliseconds(1500);
sf::Time DE_Lehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* DE_Lehrer::texture = nullptr;


// public static Methoden
void DE_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/DE/DE-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

}

void DE_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
DE_Lehrer::DE_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture)
{}

DE_Lehrer::~DE_Lehrer()
{
}

TowerType DE_Lehrer::getTowerType()
{
	return this->towerType;
}

AmmoType DE_Lehrer::getAmmoType() {
	return this->ammoType;
}

void DE_Lehrer::HasAttacked()
{
	this->readyToAttack = false;
	this->clock.restart();
	this->remainingAttackTime = sf::milliseconds(0);
	this->fireRateDiviation = sf::milliseconds(Randomizer::randomize((int)this->maximumFireRateDiviation.asMilliseconds() * 2, -(int)this->maximumFireRateDiviation.asMilliseconds()));
}

//public Methoden
void DE_Lehrer::update()
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

