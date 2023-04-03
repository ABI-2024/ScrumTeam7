#include "MA_Ammo.h"

#include "Window.h"

#include <math.h>

// public static Variables
AmmoType MA_Ammo::ammoType = AmmoType::Mathe;


// static Variables private
float MA_Ammo::damage = 20.f;
sf::Vector2f MA_Ammo::dir = sf::Vector2f(400.f, 0);
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
AmmoType MA_Ammo::getAmmoType()
{
	return this->ammoType;
}

float MA_Ammo::getDamage()
{
	return this->damage;
}

bool MA_Ammo::CollisionWithEnemy(sf::FloatRect& Enemy)
{
	return sf::FloatRect(this->body.getGlobalBounds()).intersects(Enemy);
}

void MA_Ammo::move()
{
	// Noch simple und Fehlerhaft
	sf::Vector2f pos = sf::Vector2f(body.getPosition().x+ (this->dir.x * dt), 150.f* (float)sin( ((double)dir.x * (double)dt + (double)body.getPosition().x) * (0.01745)) + offset.y );
	
	this->body.setPosition(pos);

	if (this->body.getPosition().x >= GameWindow::getMainView().getSize().x) {
		this->hit = true;
	}
}

void MA_Ammo::update()
{
	this->move();
}
