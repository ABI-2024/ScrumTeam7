#include "INF_Lehrer.h"

#include "Randomizer.h"
#include "AActors.h"
#include "Window.h"

// public static Variables 
AllyType INF_Lehrer::type;

// private static Variables 
int INF_Lehrer::Cost = 20;
float INF_Lehrer::Health = 200;
sf::Time INF_Lehrer::fireRate = sf::milliseconds(1500);
sf::Time INF_Lehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* INF_Lehrer::texture = nullptr;
sf::Font* INF_Lehrer::font = nullptr;
sf::Time INF_Lehrer::animationTime = sf::milliseconds(500);


// public static Methoden
void INF_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/INF/INF-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}

		font = new sf::Font();
		font->loadFromFile("resource/fonts/Broken Console Bold.otf");
	}

}

void INF_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;

	delete font;
	font = nullptr;
}


// Constructur & Destructur
INF_Lehrer::INF_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture)
	, powerup(0), level(PowerLevel::OnlyMouse)
{
	ipp.setFont(*font);
	ipp.setCharacterSize(40);
	ipp.setString("i++");
	ipp.setOrigin(ipp.getGlobalBounds().width/2,ipp.getGlobalBounds().height/2);
	ipp.setFillColor( sf::Color::Green );
	ipp.setPosition({ 400 + 150 * tilePosition.x, 150 + 150 * tilePosition.y - 60});
}

INF_Lehrer::~INF_Lehrer()
{
	male->play();
}

//public Methoden
void INF_Lehrer::takeDamage(float damage) {
	health -= damage;
	if (health <= 0) {
		status.alive = false;
	}
}

void INF_Lehrer::update()
{
	if (health <= Health / 5) {
		body.setFillColor({ 139,0,0 }); //DarkRed
	}
	else if (health <= Health / 2) {
		body.setFillColor({ 255,48,48 }); //firebrick1

	}
	else if (health <= Health * 0.8) {
		body.setFillColor({ 255,99,71 }); //tomato1
	}

	if ((clock.getElapsedTime() + this->remainingAttackTime) * status.multi_Attackspeed >= fireRate + fireRateDiviation && enemyOnLines[(int)tilePosition.y]) {
		
		switch (level)
		{
		case INF_Lehrer::PowerLevel::OnlyMouse:
			AActors::create(AmmoType::Inf_weak, this->body.getPosition());
			break;

		case INF_Lehrer::PowerLevel::MouseKeyboard:
			if (Randomizer::randomize(2) == 1) {
				AActors::create(AmmoType::Inf_weak, this->body.getPosition());
			}
			else {
				AActors::create(AmmoType::Inf_medium, this->body.getPosition());
			}
			break;

		case INF_Lehrer::PowerLevel::OnlyKeyboard:
			AActors::create(AmmoType::Inf_medium, this->body.getPosition());
			break;

		case INF_Lehrer::PowerLevel::KeyboardMonitor:
			if (Randomizer::randomize(2) == 1) {
			AActors::create(AmmoType::Inf_medium, this->body.getPosition());
			}
			else {
			AActors::create(AmmoType::Inf_strong, this->body.getPosition());
			}
			break;

		case INF_Lehrer::PowerLevel::OnlyMonitor:
			AActors::create(AmmoType::Inf_strong, this->body.getPosition());
			break;
		default:
			break;
		}

		if (level != PowerLevel::OnlyMonitor && powerup >= 1) {
			animationTimer.restart();
			level = PowerLevel(int(level) + 1);
			powerup = 0;
		}
		else {
			powerup++;
		}



		fireRateDiviation = sf::milliseconds(maximumFireRateDiviation.asMilliseconds() / Randomizer::randomize(9, 1));
		this->remainingAttackTime = sf::seconds(0);
		clock.restart();
	}

	if (!status.alive) {
		AActors::destroy(this);
	}
}

void INF_Lehrer::render()
{
	Window.draw(body);

	if (animationTimer.getElapsedTime() <= animationTime) {
		Window.draw(ipp);
	}

}

