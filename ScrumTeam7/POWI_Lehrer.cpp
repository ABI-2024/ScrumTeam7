#include "POWI_Lehrer.h"

#include "Randomizer.h"
#include "AActors.h"
#include "Window.h"

// public static Variables 
AllyType POWI_Lehrer::type = AllyType::RELI_Lehrer;


// private static Variables 
int POWI_Lehrer::Cost = 20;
float POWI_Lehrer::Health = 100;
sf::Time POWI_Lehrer::bookRespawnTime = sf::milliseconds(3000);
sf::Texture* POWI_Lehrer::texture = nullptr;


// public static Methoden
void POWI_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/POWI/POWI-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

	POWI_Book::LoadTexture();

}

void POWI_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;

	POWI_Book::unLoadTexture();
}


// Constructur & Destructur
POWI_Lehrer::POWI_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture), book(body.getPosition())
{}

POWI_Lehrer::~POWI_Lehrer()
{
	female->play();
}


//public Methoden
void POWI_Lehrer::takeDamage(float damage) {

	if (book.isAlive()) {
		book.takeDamage(damage);
		if (!book.isAlive()) {
			this->remainingAttackTime = sf::seconds(0);
			clock.restart();
		}
	}
	else {
		health -= damage;
		if (health <= 0) {
			status.alive = false;
		}
	}
}

void POWI_Lehrer::update()
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

	if (	!book.isAlive()) {
		if (clock.getElapsedTime() + this->remainingAttackTime >= bookRespawnTime) {

			book.reset();
		}
	}
	else {
		book.heal(5.f*dt);
	}

	if (!status.alive) {
		AActors::destroy(this);
	}
}

void POWI_Lehrer::render()
{
	Window.draw(body);

	if (book.isAlive()) {
		book.render();
	}
}

