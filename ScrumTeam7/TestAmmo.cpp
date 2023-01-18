#include "TestAmmo.h"

#include <iostream>

#include "Window.h"

AmmoType TestAmmo::ammoType = AmmoType::TestAmmo;

float TestAmmo::damage = 20.f;

sf::Vector2f TestAmmo::dir = sf::Vector2f(400.f,0);

sf::Texture* TestAmmo::texture = nullptr;

void TestAmmo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();	
	}
	if (!texture->loadFromFile("resource/Textures/Basketball.png")) {
		std::cout << "\tFail: Textur not loaded!\n\n";

		if (!texture->loadFromFile("resource/Textures/DefaultTexture.png")) {
			std::cout << "\tFail: Textur not loaded!\n\n";
		}
	}
}

void TestAmmo::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}



TestAmmo::TestAmmo(sf::Vector2f TowerPosition)
	:BaseAmmo(TowerPosition, texture)
{}

TestAmmo::~TestAmmo() {}

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
	return sf::FloatRect(this->Body.getGlobalBounds()).intersects(Enemy);
}

void TestAmmo::move()
{
	this->Body.move(this->dir * dt);

	if (this->Body.getPosition().x >= GameWindow::getMainView().getSize().x) {
		this->hit = true;
	}
}

void TestAmmo::update()
{
	this->move();
}
