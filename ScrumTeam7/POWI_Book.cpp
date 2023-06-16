#include "POWI_Book.h"

#include "Window.h"
#include "AActors.h"

#define HEALTH 500.f

sf::Texture* POWI_Book::texture = nullptr;
sf::Font* POWI_Book::font = nullptr;
sf::Time POWI_Book::animationTime = sf::milliseconds(1000);

void POWI_Book::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/POWI/POWI_Buch.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}

		font = new sf::Font();
		font->loadFromFile("resource/fonts/Broken Console Bold.otf");
	}
}

void POWI_Book::unLoadTexture()
{
	delete texture;
	texture = nullptr;

	delete font;
	font = nullptr;
}

POWI_Book::POWI_Book(sf::Vector2f position)
	:alive(true), health(HEALTH), revenue(0)
{
	body.setPosition(position);
	body.setSize( { 42.1875f * 12.f / 9.f, 42.1875f * 17.f / 9.f } );
	body.setOrigin( { body.getSize().x / 8.f , body.getSize().y / 2.f } );

	body.setTexture(texture, 0);

	stongs.setFont(*font);
	stongs.setCharacterSize(40);
	stongs.setString("stonks");
	stongs.setOrigin(stongs.getGlobalBounds().width / 2, stongs.getGlobalBounds().height / 2);
	stongs.setFillColor(sf::Color::Green);
	stongs.setPosition({ position.x,position.y - 60 });

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

	revenue += 1.f*dt;
	
	if (revenue >= 25) {
		AActors::addCollectedRevenue(revenue);
		animationTimer.restart();
		revenue = 0;
	}
	Window.draw(body);

	if (animationTimer.getElapsedTime() <= animationTime) {
		Window.draw(stongs);
	}
}
