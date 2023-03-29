#include "TestEnemy.h"

#include "Window.h"
#include "Randomizer.h"

// static Variables

EnemyType TestEnemy::enemyType = EnemyType::TestEnemy;

float TestEnemy::Health = 200;
float TestEnemy::Damage = 20;

int TestEnemy::revenue = 5;

sf::Vector2f TestEnemy::dir = sf::Vector2f(-10, 0);

sf::Texture* TestEnemy::texture = nullptr;

sf::Time TestEnemy::attackSpeed = sf::milliseconds(750);


// public static Methoden
void TestEnemy::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture[2];

		if (!texture[0].loadFromFile("resource/Textures/Schueler/STD-Student-m.png")) {
			texture[0].loadFromFile("resource/Textures/DefaultTexture.png");
		}

		if (!texture[1].loadFromFile("resource/Textures/Schueler/STD-Student-w.png")) {
			texture[1].loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void TestEnemy::unLoadTexture()
{
	delete[] texture;
	texture = nullptr;
}


// Constructur & Destructur
TestEnemy::TestEnemy(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health, tilePosition, &texture[0])
{
	body.setTexture(&texture[Randomizer::randomize(2)] , false);
}

TestEnemy::~TestEnemy() {}

// public get-Methoden
int TestEnemy::getRevenue() {
	return revenue;
}

EnemyType TestEnemy::getEnemyType()
{
	return this->enemyType;
}

float TestEnemy::getDamage()
{
	return this->Damage;
}

// public Methoden
bool TestEnemy::CollisionWithTower(sf::FloatRect& Tower)
{
	if (sf::FloatRect(this->body.getGlobalBounds()).intersects(Tower)) {
		movable = false;
		return 1;
	}
	else {
		return 0;
	}
}

void TestEnemy::move()
{
	if (movable) {
		this->body.move(this->dir * dt);
	}
	else {
		movable = true;
	}
}

void TestEnemy::update()
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

	if (this->attackSpeed <= this->clock.getElapsedTime()) {
		readyToAttack = true;
	}
	this->move();
}



