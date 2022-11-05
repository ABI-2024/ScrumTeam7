#include "TestAmmo.h"

#include <iostream>

#include "Window.h"

int TestAmmo::Total = 0;
int TestAmmo::ammoType = 1;

float TestAmmo::damage = 20.f;
sf::Vector2f TestAmmo::dir = sf::Vector2f(14.f,0);

sf::Texture* TestAmmo::texture = nullptr;

void TestAmmo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();	
	}
	if (!texture->loadFromFile("Textures/Basketball.png")) {
		std::cout << "\tFail: Textur not loaded!\n\n";

		if (!texture->loadFromFile("Textures/DefaultTexture.png")) {
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
{

	this->initBaseVariables(this->AmmoType, this->damage ,TowerPosition, texture);
}

TestAmmo::~TestAmmo()
{
	
}

bool TestAmmo::CollisionWithEnemy(sf::FloatRect& Enemy)
{
	return sf::FloatRect(this->Body.getGlobalBounds()).intersects(Enemy);
}

void TestAmmo::move()
{
	this->Body.move(this->dir);
	if (this->Body.getPosition().x >= GameWindow::getWindow().getSize().x) {
		this->hit = true;
	}
}

void TestAmmo::update()
{
	this->move();
}
