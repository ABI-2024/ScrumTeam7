#include "INF_Lehrer.h"

#include "Randomizer.h"
#include "AActors.h"

// public static Variables 
AllyType INF_Lehrer::type;

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
	: BaseTower(this->Health, tilePosition, texture)
	, powerup(0), level(PowerLevel::OnlyMouse)
{}

INF_Lehrer::~INF_Lehrer()
{
	male->play();
}

//public Methoden
void INF_Lehrer::takeDamage(float damage) {
	health -= damage;
	if (health <= 0) {
		status.alive = false;
	}
}

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

	if ((clock.getElapsedTime() + this->remainingAttackTime) * status.multi_Attackspeed >= fireRate + fireRateDiviation && enemyOnLines[(int)tilePosition.y]) {
		
		switch (level)
		{
		case INF_Lehrer::PowerLevel::OnlyMouse:
			AActors::create(AmmoType::Inf_weak, this->body.getPosition());
			break;

		case INF_Lehrer::PowerLevel::MouseKeyboard:
			if (Randomizer::randomize(2) == 1) {
				AActors::create(AmmoType::Inf_weak, this->body.getPosition());
			}
			else {
				AActors::create(AmmoType::Inf_medium, this->body.getPosition());
			}
			break;

		case INF_Lehrer::PowerLevel::OnlyKeyboard:
			AActors::create(AmmoType::Inf_medium, this->body.getPosition());
			break;

		case INF_Lehrer::PowerLevel::KeyboardMonitor:
			if (Randomizer::randomize(2) == 1) {
			AActors::create(AmmoType::Inf_medium, this->body.getPosition());
			}
			else {
			AActors::create(AmmoType::Inf_strong, this->body.getPosition());
			}
			break;

		case INF_Lehrer::PowerLevel::OnlyMonitor:
			AActors::create(AmmoType::Inf_strong, this->body.getPosition());
			break;
		default:
			break;
		}

		if (level != PowerLevel::OnlyMonitor && powerup >= 1) {
			level = PowerLevel(int(level) + 1);
			powerup = 0;
		}
		else {
			powerup++;
		}



		fireRateDiviation = sf::milliseconds(maximumFireRateDiviation.asMilliseconds() / Randomizer::randomize(9, 1));
		this->remainingAttackTime = sf::seconds(0);
		clock.restart();
	}

	if (!status.alive) {
		AActors::destroy(this);
	}
}

