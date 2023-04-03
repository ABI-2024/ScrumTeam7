#include "Projectil_Pi.h"

#include "Window.h"

// public static Variables
AmmoType Projectil_Pi::ammoType = AmmoType::Pi;


// static Variables private
float Projectil_Pi::damage = 20.f;
sf::Vector2f Projectil_Pi::dir = sf::Vector2f(400.f, 0);
sf::Texture* Projectil_Pi::texture = nullptr;


// public static Methoden 
void Projectil_Pi::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Basketball.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Projectil_Pi::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Projectil_Pi::Projectil_Pi(sf::Vector2f TowerPosition)
	:BaseAmmo(TowerPosition, texture)
{}

Projectil_Pi::~Projectil_Pi() {}


// public Methoden
AmmoType Projectil_Pi::getAmmoType()
{
	return this->ammoType;
}

float Projectil_Pi::getDamage()
{
	return this->damage;
}

bool Projectil_Pi::CollisionWithEnemy(sf::FloatRect& Enemy)
{
	return sf::FloatRect(this->body.getGlobalBounds()).intersects(Enemy);
}

void Projectil_Pi::move()
{
	this->body.move(this->dir * dt);

	if (this->body.getPosition().x >= GameWindow::getMainView().getSize().x) {
		this->hit = true;
	}
}

void Projectil_Pi::update()
{
	this->move();
}

