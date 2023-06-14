#include "RELI_Lehrer.h"

#include "Randomizer.h"
#include "AActors.h"
#include "Window.h"

// public static Variables 
AllyType RELI_Lehrer::type = AllyType::RELI_Lehrer;


// private static Variables 
float RELI_Lehrer::Health = 200;
sf::Time RELI_Lehrer::fireRate = sf::milliseconds(4000);
sf::Time RELI_Lehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Time RELI_Lehrer::bookRespawnTime = sf::milliseconds(3000);
sf::Texture* RELI_Lehrer::texture = nullptr;


// public static Methoden
void RELI_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/RELI/RELI-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

	RELI_Book::LoadTexture();
}

void RELI_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;

	RELI_Book::unLoadTexture();
}


// Constructur & Destructur
RELI_Lehrer::RELI_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture), book(body.getPosition())
{}

RELI_Lehrer::~RELI_Lehrer()
{
	female->play();
}


//public Methoden
void RELI_Lehrer::takeDamage(float damage) {

	if (book.isAlive()) {
		// wenn das Buch am "Leben" ist bekommt das buch schaden
		book.takeDamage(damage);
		if (!book.isAlive()) {
			this->remainingAttackTime = sf::seconds(0);
			clock.restart();
		}
	}
	else {
		// Andernfalls bekommt der Lehrer schaden
		health -= damage;
		if (health <= 0) {
			status.alive = false;
		}
	}
}

void RELI_Lehrer::update()
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

	if (!book.isAlive()) {
		if (clock.getElapsedTime() + this->remainingAttackTime >= bookRespawnTime) {

			book.reset();
		}
	}
	else {
		book.heal(10.f * dt);

		if (clock.getElapsedTime() + this->remainingAttackTime >= fireRate + fireRateDiviation && enemyOnLines[(int)tilePosition.y]) {
			AActors::create(AmmoType::RELI_Ammo, this->body.getPosition());

			fireRateDiviation = sf::milliseconds(maximumFireRateDiviation.asMilliseconds() / Randomizer::randomize(9, 1));
			this->remainingAttackTime = sf::seconds(0);
			clock.restart();
		}
	}
	

	if (!status.alive) {
		AActors::destroy(this);
	}
}

void RELI_Lehrer::render()
{
	Window.draw(body);

	if (book.isAlive()) {
		book.render();
	}
}


