#include "POWI_Book.h"

#include "Window.h"

#define HEALTH 1000.f

sf::Texture* POWI_Book::texture = nullptr;

void POWI_Book::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/POWI/POWI_Buch.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void POWI_Book::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}

POWI_Book::POWI_Book(sf::Vector2f position)
	:alive(true), health(HEALTH)
{
	body.setPosition(position);
	body.setSize( { 42.1875f * 12.f / 9.f, 42.1875f * 17.f / 9.f } );
	body.setOrigin( { body.getSize().x / 8.f , body.getSize().y / 2.f } );

	body.setTexture(texture, 0);
}

POWI_Book::~POWI_Book()
{
}

bool POWI_Book::isAlive()
{
	return alive;
}

void POWI_Book::reset()
{
	alive = true;
	health = HEALTH;
}

void POWI_Book::takeDamage(const float& damage)
{
	health -= damage;
	if (health <= 0) {
		alive = false;
	}
}

void POWI_Book::heal(const float& heal)
{
	if (health < HEALTH) {
		health += heal;
		if (health > HEALTH) {
			health = HEALTH;
		}
	}
}

void POWI_Book::render()
{
	Window.draw(body);
}
