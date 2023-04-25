#include "TestAmmo.h"

#include "Window.h"

// public static Variables
AmmoType TestAmmo::ammoType = AmmoType::TestAmmo;


// static Variables private
float TestAmmo::damage = 20.f;
sf::Vector2f TestAmmo::dir = sf::Vector2f(400.f,0);
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
	status_Effect = { Status_Type::stun, 100.f, sf::milliseconds(0) };
}

TestAmmo::~TestAmmo() {}


// public Methoden
AmmoType TestAmmo::getAmmoType()
{
	return this->ammoType;
}

float TestAmmo::getDamage()
{
	return this->damage;
}

bool TestAmmo::CollisionWithEnemy(sf::FloatRect& Enemy)
{
	return sf::FloatRect(this->body.getGlobalBounds()).intersects(Enemy);
}

void TestAmmo::move()
{
	this->body.move(this->dir * dt);

	if (this->body.getPosition().x >= GameWindow::getMainView().getSize().x) {
		this->hit = true;
	}
}

void TestAmmo::update()
{
	this->move();
}
