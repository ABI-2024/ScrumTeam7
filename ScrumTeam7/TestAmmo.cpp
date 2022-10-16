#include "TestAmmo.h"

float TestAmmo::damage = 10.f;
sf::Vector2f TestAmmo::dir = sf::Vector2f(14.f,0);

sf::Texture* TestAmmo::texture = nullptr;

void TestAmmo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();	
	}
	if (!texture->loadFromFile("Textures/Basketball.png")) {
		cout << "\tFail: Textur not loaded!\n\n";

		if (!texture->loadFromFile("Textures/DefaultTexture.png")) {
			cout << "\tFail: Textur not loaded!\n\n";
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
	if (this->texture == nullptr) {
		//TestAmmo::LoadTexture();
	}

	this->initBaseVariables(TowerPosition, texture);
}

TestAmmo::~TestAmmo()
{

}

void TestAmmo::move()
{
	this->Body.move(this->dir);

	if (this->Body.getPosition().x >= GameWindow::getWindow().getSize().x)
	{
		this->hit = true;
	}
}

void TestAmmo::update()
{
	this->move();
}

void TestAmmo::render()
{
	GameWindow::getWindow().draw(this->Body);
}