#include "TestEnemy.h"

// static Variables
float TestEnemy::EnemyHealth = 200;
float TestEnemy::damage = 20;

sf::Vector2f TestEnemy::dir = sf::Vector2f(-0.5, 0);

sf::Texture* TestEnemy::texture = nullptr;

sf::Time TestEnemy::attackSpeed = seconds(3);


// private Methoden
void TestEnemy::initVariables(float linePosition)
{
	this->initBaseVariables(this->EnemyHealth, linePosition, this->texture);
}


// static Methoden
void TestEnemy::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();
	}

	if (!texture->loadFromFile("Textures/DefaultTexture.png")) {
		std::cout << "\tFail: Textur not loaded!\n\n";
	}

}

void TestEnemy::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
TestEnemy::TestEnemy()
{
}

TestEnemy::TestEnemy(float linePosition)
{
	this->initVariables(linePosition);
}

TestEnemy::~TestEnemy()
{
}


// public Methoden
void TestEnemy::move()
{
	this->Body.move(dir);
}

void TestEnemy::update()
{
	move();
}

void TestEnemy::render()
{
	GameWindow::getWindow().draw( this->Body);
}
