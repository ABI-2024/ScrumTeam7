#include "TestAmmo.h"

#include "Window.h"
#include "AActors.h"

// public static Variables
AmmoType TestAmmo::ammoType = AmmoType::TestAmmo;


// static Variables private
float TestAmmo::damage = 40.f;
sf::Vector2f TestAmmo::dir = sf::Vector2f(600.f,0);
sf::Texture* TestAmmo::texture = nullptr;


// public static Methoden 
void TestAmmo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/SP/SP-Ammo.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void TestAmmo::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
TestAmmo::TestAmmo(sf::Vector2f TowerPosition)
	:BaseAmmo(TowerPosition, texture)
{
}

TestAmmo::~TestAmmo() {}


// public Methoden

void TestAmmo::move()
{
	this->body.move(this->dir * dt);

	if (body.getPosition().x >= 1600.f + body.getSize().x/2.f) {
		status.alive = false;
	}
}

void TestAmmo::update()
{
	this->move();

	Entity* tmp =  AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::enemies);
	if (tmp != nullptr) {
		tmp->takeDamage(this->damage);
		status.alive = false;

		hitSound->setVolume(100 * GameWindow::getSettings()->MasterVolume * GameWindow::getSettings()->SoundVolume / 10000);
		hitSound->play();

	}



	if (!status.alive) {
		AActors::destroy(this);
	}
}
