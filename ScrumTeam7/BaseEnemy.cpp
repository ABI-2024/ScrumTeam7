#include "BaseEnemy.h"

#include "Window.h"
#include"AActors.h"

sf::SoundBuffer* BaseEnemy::bufferMale = nullptr;
sf::SoundBuffer* BaseEnemy::bufferFemale = nullptr;
sf::Sound* BaseEnemy::male = nullptr;
sf::Sound* BaseEnemy::female = nullptr;

void BaseEnemy::loadSound()
{
	if (bufferMale == nullptr) {
		bufferMale = new sf::SoundBuffer();
		bufferFemale = new sf::SoundBuffer();

		bufferMale->loadFromFile("resource/Sound/Effects/male-death.wav");
		bufferFemale->loadFromFile("resource/Sound/Effects/Female-Death.wav");

		male = new sf::Sound();
		male->setBuffer(*bufferMale);

		female = new sf::Sound();
		female->setBuffer(*bufferFemale);
	}
}

void BaseEnemy::unloadSound()
{
	if (bufferMale != nullptr) {

		delete bufferMale;
		delete bufferFemale;

		delete male;
		delete female;

		bufferMale = nullptr;
		bufferFemale = nullptr;

		male = nullptr;
		female = nullptr;

	}
}


// Constructur & Destructur
BaseEnemy::BaseEnemy(float Health, sf::Vector2f tilePosition, sf::Texture* texture)
	: Entity({ 75.f, 150.f }, { GameWindow::getMainView().getSize().x, 150.f + 150.f * tilePosition.y }), movable(true), health(Health), tilePosition(tilePosition)
{
	this->statusprocs = new std::vector< StatusProc*>;

	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x - this->body.getSize().x / 8.f, this->body.getPosition().y + this->body.getSize().y / 2);
	this->shadow.setSize(sf::Vector2f(this->body.getSize().x, 37.5f));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture, 0);
}

BaseEnemy::~BaseEnemy()
{}

sf::Vector2f BaseEnemy::getTilePosition()
{
	return this->tilePosition;
}

const CollisionType& BaseEnemy::getCollisionType()
{
	return CollisionType::enemies;
}


// public get-Methoden

sf::FloatRect BaseEnemy::getFloaRect()
{
	return sf::FloatRect(this->body.getGlobalBounds());
}


sf::Vector2f BaseEnemy::getPosition()
{
	return body.getPosition();
}

void BaseEnemy::takeDamage(float damage)
{
	health -= damage;
	if (health <= 0) {
		status.alive = false;
	}
}

// public Methoden
void BaseEnemy::pauseEntitiy()
{
	this->remainingAttackTime = this->clock.restart() + this->remainingAttackTime ;
}

void BaseEnemy::continueEntitiy()
{
	this->clock.restart();
}
