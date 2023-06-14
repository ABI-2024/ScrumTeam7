#include "RELI_Ammo.h"

#include "Window.h"
#include "AActors.h"

// public static Variables
AmmoType RELI_Ammo::ammoType = AmmoType::RELI_Ammo;


// static Variables private
sf::Vector2f RELI_Ammo::dir = sf::Vector2f(600.f, 0);
sf::Texture* RELI_Ammo::texture = nullptr;


// public static Methoden 
void RELI_Ammo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/RELI/RELI-Ammo.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void RELI_Ammo::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
RELI_Ammo::RELI_Ammo(sf::Vector2f TowerPosition)
	:BaseAmmo(TowerPosition, texture), startPosition(TowerPosition), enemiesHit(2)
{
}

RELI_Ammo::~RELI_Ammo() {}


// public Methoden

void RELI_Ammo::move()
{
	this->body.move(this->dir * dt);

	// Reichweite
	if (body.getPosition().x >= startPosition.x + 450.f) {
		status.alive = false;
	}

	// Rechter Rand
	if (body.getPosition().x >= 1600.f + body.getSize().x / 2.f) {
		status.alive = false;
	}
}

void RELI_Ammo::update()
{
	this->move();

	// Collision
	std::vector<Entity*>* tmp = AActors::CollisionPoly(body.getGlobalBounds(), CollisionType::enemies);
	if (tmp != nullptr) {
		for (int i = 0; i < tmp->size(); i++) {

			if (enemiesHit > 0) {
				// Status effect
				(*tmp)[i]->addStatusEffect(StatusEffect(StatusType::stun, sf::milliseconds(200), 20.f));
				enemiesHit--;
			}
			else {
				status.alive = false;
			}
		}
		delete tmp;
	}


	// löscht sich selbst, wenn nich am Leben
	if (!status.alive) {
		AActors::destroy(this);
	}
}

