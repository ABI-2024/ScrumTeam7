#include "INF_Lehrer.h"

#include "Randomizer.h"

// public static Variables 
TowerType INF_Lehrer::towerType = TowerType::INF_Lehrer;
AmmoType INF_Lehrer::ammoType[3] = { AmmoType::Inf_weak, AmmoType::Inf_medium, AmmoType::Inf_strong };

// private static Variables 
int INF_Lehrer::Cost = 20;
float INF_Lehrer::Health = 200;
sf::Time INF_Lehrer::fireRate = sf::milliseconds(1500);
sf::Time INF_Lehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* INF_Lehrer::texture = nullptr;


// public static Methoden
void INF_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/INF/INF-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

}

void INF_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
INF_Lehrer::INF_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture), nextShot(ammoType[0])
	, powerup(0), level(PowerLevel::OnlyMouse)
{}

INF_Lehrer::~INF_Lehrer()
{
}

TowerType INF_Lehrer::getTowerType()
{
	return this->towerType;
}

AmmoType INF_Lehrer::getAmmoType() {

	switch (level)
	{
	case INF_Lehrer::PowerLevel::OnlyMouse:
		nextShot = ammoType[0];
		break;
	case INF_Lehrer::PowerLevel::MouseKeyboard:
		nextShot = ammoType[ Randomizer::randomize(2) ];
		break;
	case INF_Lehrer::PowerLevel::OnlyKeyboard:
		nextShot = ammoType[1];
		break;
	case INF_Lehrer::PowerLevel::KeyboardMonitor:
		nextShot = ammoType[Randomizer::randomize(2) +1];
		break;
	case INF_Lehrer::PowerLevel::OnlyMonitor:
		nextShot = ammoType[2];
		break;
	default:
		break;
	}

	return this->nextShot;
}

void INF_Lehrer::HasAttacked()
{
	this->readyToAttack = false;
	this->clock.restart();
	this->remainingAttackTime = sf::milliseconds(0);
	this->fireRateDiviation = sf::milliseconds(Randomizer::randomize((int)this->maximumFireRateDiviation.asMilliseconds() * 2, -(int)this->maximumFireRateDiviation.asMilliseconds()));



	if (powerup >= 3 and level != PowerLevel::OnlyMonitor) {
		((int&)level)++;
		powerup = 0;
	}
	else {
		powerup++;
	}
}

//public Methoden
void INF_Lehrer::update()
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

