#include "MA_Ammo.h"

#include "Window.h"
#include "AActors.h"

#include <math.h>

// public static Variables
AmmoType MA_Ammo::ammoType = AmmoType::Mathe;


// static Variables private
float MA_Ammo::damage = 70.f;
sf::Vector2f MA_Ammo::dir = sf::Vector2f(200.f, 0);
sf::Texture* MA_Ammo::texture = nullptr;


// public static Methoden 
void MA_Ammo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/MA/MA-Ammo.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void MA_Ammo::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
MA_Ammo::MA_Ammo(sf::Vector2f TowerPosition)
	:BaseAmmo(TowerPosition, texture)
{
	offset = TowerPosition;
}

MA_Ammo::~MA_Ammo() {}


// public Methoden

void MA_Ammo::move()
{
	// Noch simple und Fehlerhaft
	sf::Vector2f pos = sf::Vector2f(body.getPosition().x+ (this->dir.x * dt), 150.f* (float)sin( ( ((double)dir.x * (double)dt+ offset.x) + (double)body.getPosition().x) * (0.02095)) + offset.y );
	
	this->body.setPosition(pos);

	if (body.getPosition().x >= 1600.f + body.getSize().x / 2.f) {
		status.alive = false;
	}
}

void MA_Ammo::update()
{
	this->move();

	Entity* tmp = AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::enemies);
	if (tmp != nullptr) {
		tmp->takeDamage(this->damage);
		status.alive = false;
	}

	if (!status.alive) {
		AActors::destroy(this);
	}
}
