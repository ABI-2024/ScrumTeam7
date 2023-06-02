#include "INF_Ammo.h"

#include "Window.h"
#include "AActors.h"

// public static Variables
AmmoType INF_Ammo::ammoType[3] = { AmmoType::Inf_weak, AmmoType::Inf_medium, AmmoType::Inf_strong };


// static Variables private
float INF_Ammo::damage[3] = { 10.f, 30.f ,90.f };
sf::Vector2f INF_Ammo::dir = sf::Vector2f(400.f, 0);
sf::Texture* INF_Ammo::texture = nullptr;


// public static Methoden 
void INF_Ammo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture[3];

		if (!texture[0].loadFromFile("resource/Textures/Lehrer/INF/INF-Ammo-weak.png")) {
			texture[0].loadFromFile("resource/Textures/DefaultTexture.png");
		}
		if (!texture[1].loadFromFile("resource/Textures/Lehrer/INF/INF-Ammo-medium.png")) {
			texture[1].loadFromFile("resource/Textures/DefaultTexture.png");
		}
		if (!texture[2].loadFromFile("resource/Textures/Lehrer/INF/INF-Ammo-strong.png")) {
			texture[2].loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void INF_Ammo::unLoadTexture()
{
	delete[] texture;
	texture = nullptr;
}


// Constructur & Destructur
INF_Ammo::INF_Ammo(sf::Vector2f TowerPosition, AmmoType type)
	:BaseAmmo(TowerPosition, &texture[0]), curendType(type)
{
	switch (type)
	{
	case AmmoType::Inf_weak: default:
		body.setSize({ 56.25f, 42.1875f});
		body.setTexture(&texture[0], 1);
		break;
	case AmmoType::Inf_medium:
		body.setSize({ 75.f, 48.875f });
		body.setTexture(&texture[1], 1);
		break;
	case AmmoType::Inf_strong:
		body.setSize({ 75.f, 70.3125f });
		body.setTexture(&texture[2], 1);
		break;
	}



}

INF_Ammo::~INF_Ammo() {}


// public Methoden
AmmoType INF_Ammo::getAmmoType()
{
	return this->curendType;
}

float INF_Ammo::getDamage()
{
	switch (curendType)
	{
	case AmmoType::Inf_weak: default:
		return this->damage[0];
		break;
	case AmmoType::Inf_medium:
		return this->damage[1];
		break;
	case AmmoType::Inf_strong:
		return this->damage[2];
		break;
	
	}
}

void INF_Ammo::move()
{
	this->body.move(this->dir * dt);

	if (body.getPosition().x >= 1600.f + body.getSize().x / 2.f) {
		alive = false;
	}
}

void INF_Ammo::update()
{
	this->move();

	Entity* tmp = AActors::CollisionSingle(this, CollisionType::enemies);
	if (tmp != nullptr) {
		tmp->takeDamage(this->getDamage());
		alive = false;
	}

	if (!alive) {
		AActors::destroy(this);
	}
}
