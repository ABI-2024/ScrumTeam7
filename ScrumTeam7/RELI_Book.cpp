#include "RELI_Book.h"

#include "Window.h"

#define HEALTH 2000.f

sf::Texture* RELI_Book::texture = nullptr;

void RELI_Book::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/RELI/RELI_Buch.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void RELI_Book::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}

RELI_Book::RELI_Book(sf::Vector2f position)
	:alive(true), health(HEALTH)
{
	body.setPosition(position);
	body.setSize({ 42.1875f * 12.f / 9.f, 42.1875f * 17.f / 9.f });
	body.setOrigin({ body.getSize().x / 8.f , body.getSize().y / 2.f });

	body.setTexture(texture, 0);
}

RELI_Book::~RELI_Book()
{
}

bool RELI_Book::isAlive()
{
	return alive;
}

void RELI_Book::reset()
{
	alive = true;
	health = HEALTH;
}

void RELI_Book::takeDamage(const float& damage)
{
	health -= damage;
	if (health <= 0) {
		alive = false;
	}
}

void RELI_Book::heal(const float& heal)
{
	if (health < HEALTH) {
		health += heal;
		if (health > HEALTH) {
			health = HEALTH;
		}
	}
}

void RELI_Book::render()
{
	Window.draw(body);
}

