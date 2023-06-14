#include "BaseAmmo.h"

#include "Window.h"


sf::SoundBuffer* BaseAmmo::buffer = nullptr;
sf::Sound* BaseAmmo::hitSound = nullptr;

void BaseAmmo::loadSound()
{
	if (buffer == nullptr) {
		buffer = new sf::SoundBuffer();

		buffer->loadFromFile("resource/Sound/Effects/Hitmarker.wav");

		hitSound = new sf::Sound();
		hitSound->setBuffer(*buffer);
	}
}

void BaseAmmo::unloadSound()
{
	if (buffer != nullptr) {

		delete buffer;
		delete hitSound;

		buffer = nullptr;
		hitSound = nullptr;

	}
}

// Constructur & Destructur
BaseAmmo::BaseAmmo(const sf::Vector2f& TowerPosition, sf::Texture* texture)
	: Entity(sf::Vector2f(42.1875f, 42.1875f), TowerPosition)
{

	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x, this->body.getPosition().y + 75.f);
	this->shadow.setSize(sf::Vector2f(75.f / 2, 37.5f / 2));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture, 0);
}

BaseAmmo::~BaseAmmo()
{
}

const CollisionType& BaseAmmo::getCollisionType()
{
	return CollisionType::allyAmmo;
}

// public Methoden
void BaseAmmo::renderShadow()
{
	this->shadow.setPosition(this->body.getPosition().x, this->body.getPosition().y + 75.f);
	Window.draw(shadow);
}

