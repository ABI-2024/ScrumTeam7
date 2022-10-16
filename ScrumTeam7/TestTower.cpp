#include "TestTower.h"

// static Variablen

int TestTower::towerCost = 0;
float TestTower::towerHealth = 200;
sf::Time TestTower::fireRate = sf::milliseconds(1500);
sf::Texture* TestTower::texture = nullptr;

// static Methoden
void TestTower::LoadTexture()
{	
	if (texture == nullptr) {
		texture = new sf::Texture();
	}

	if (!texture->loadFromFile("Textures/SportLehre1.png")) {
		std::cout << "\tFail: Textur not loaded!\n\n";

		if (!texture->loadFromFile("Textures/DefaultTexture.png")) {
			std::cout << "\tFail: Textur not loaded!\n\n";
		}
	}
	
}

void TestTower::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}

// private Methden
void TestTower::initVariables(sf::Vector2f tilePosition)
{
	this->initBaseVariables(this->towerHealth, tilePosition, texture);
}

// Constructur & Destructur
TestTower::TestTower()
{
}

TestTower::TestTower(sf::Vector2f tilePosition)
{
	this->initVariables(tilePosition);
}

TestTower::~TestTower()
{
}

//public Methoden
void TestTower::shoot()
{
	if (this->clock.getElapsedTime() >= this->fireRate) {
		ammo.push_back(new TestAmmo(this->Body.getPosition()));
		clock.restart();
	}
}

void TestTower::ammoDelete()
{
	int pos = 0;
	for (auto i = ammo.begin(); i != ammo.end(); ++i, pos++) {
		if ((*i)->isHit()) {
			delete ammo[pos];
			i = ammo.erase(ammo.begin()+pos);
			break;			
		}
	}
}

void TestTower::update()
{
	this->shoot();
	this->ammoDelete(); 
	for (auto i = ammo.begin(); i != ammo.end(); ++i) {
		(*i)->move();
	}
}

void TestTower::render()
{
	GameWindow::getWindow().draw(this->Body);
	for (auto i = ammo.begin(); i != ammo.end(); ++i) {
		(*i)->render();
	}
}
