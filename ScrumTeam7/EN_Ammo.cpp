#include "EN_Ammo.h"

#include "Window.h"

// public static Variables
AmmoType EN_Ammo::ammoType[4] = { AmmoType::Englisch_weak, AmmoType::Englisch_medium, AmmoType::Englisch_strong, AmmoType::Englisch_strongest };


// static Variables private
float EN_Ammo::damage[4] = { 10.f, 20.f ,40.f, 80.f };
sf::Vector2f EN_Ammo::dir = sf::Vector2f(400.f, 0);
sf::Texture* EN_Ammo::texture = nullptr;


// public static Methoden 
void EN_Ammo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture[4];

		if (!texture[0].loadFromFile("resource/Textures/Lehrer/EN/EN-Ammo-weak.png")) {
			texture[0].loadFromFile("resource/Textures/DefaultTexture.png");
		}
		if (!texture[1].loadFromFile("resource/Textures/Lehrer/EN/EN-Ammo-medium.png")) {
			texture[1].loadFromFile("resource/Textures/DefaultTexture.png");
		}
		if (!texture[2].loadFromFile("resource/Textures/Lehrer/EN/EN-Ammo-strong.png")) {
			texture[2].loadFromFile("resource/Textures/DefaultTexture.png");
		}
		if (!texture[3].loadFromFile("resource/Textures/Lehrer/EN/EN-Ammo-strongest.png")) {
			texture[3].loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void EN_Ammo::unLoadTexture()
{
	delete[] texture;
	texture = nullptr;
}


// Constructur & Destructur
EN_Ammo::EN_Ammo(sf::Vector2f TowerPosition, AmmoType type)
	:BaseAmmo(TowerPosition, &texture[0]), curendType(type)
{
	switch (type)
	{
	case AmmoType::Englisch_weak: default:
		body.setTexture(&texture[0], 1);
		break;
	case AmmoType::Englisch_medium:
		body.setTexture(&texture[1], 1);
		break;
	case AmmoType::Englisch_strong:
		this->status_Effect = { Status_Type::stun, 0.f , sf::milliseconds(500) };
		body.setTexture(&texture[2], 1);
		break;
	case AmmoType::Englisch_strongest:
		this->status_Effect = { Status_Type::stun, 50.f , sf::milliseconds(1500) };
		body.setTexture(&texture[3], 1);
		break;
	}
}

EN_Ammo::~EN_Ammo() {}


// public Methoden
AmmoType EN_Ammo::getAmmoType()
{
	return this->curendType;
}

float EN_Ammo::getDamage()
{
	switch (curendType)
	{
	case AmmoType::Englisch_weak: default:
		return this->damage[0];
		break;
	case AmmoType::Englisch_medium:
		return this->damage[1];
		break;
	case AmmoType::Englisch_strong:
		return this->damage[2];
		break; 
	case AmmoType::Englisch_strongest:
		return this->damage[3];
		break;

	}
}

void EN_Ammo::move()
{
	this->body.move(this->dir * dt);
}

void EN_Ammo::update()
{
	this->move();
}
