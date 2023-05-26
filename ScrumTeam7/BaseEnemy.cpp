#include "BaseEnemy.h"

#include "Window.h"

// Constructur & Destructur
BaseEnemy::BaseEnemy(float Health, sf::Vector2f tilePosition, sf::Texture* texture)
	: Entity(), movable(true), health(Health), tilePosition(tilePosition)
{
	this->body.setPosition(GameWindow::getMainView().getSize().x, 150.f + 150.f * this->tilePosition.y);
	this->body.setSize(sf::Vector2f(75.f, 150.f));
	this->body.setOrigin(sf::Vector2f(this->body.getSize().x / 2, this->body.getSize().y / 2));
	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x - this->body.getSize().x / 8.f, this->body.getPosition().y + this->body.getSize().y / 2);
	this->shadow.setSize(sf::Vector2f(this->body.getSize().x, 37.5f));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture, 0);
}

BaseEnemy::~BaseEnemy()
{}


// public get-Methoden

const sf::Vector2f& BaseEnemy::getTilePosition()
{
	return tilePosition;
}

sf::FloatRect BaseEnemy::getFloaRect()
{
	return sf::FloatRect(this->body.getGlobalBounds());
}


sf::Vector2f BaseEnemy::getPosition()
{
	return body.getPosition();
}

// public Methoden

void BaseEnemy::addStatus_Proc(Status_Effect nStatus)
{
	procs.push_back(Status_Proc<BaseEnemy>(nStatus, (BaseEnemy*)this));
}

void BaseEnemy::updateStatus_Proc()
{
	for (auto i = procs.begin(); i != procs.end(); i++) {
		i->effect();

		if (!i->active) {
			i = procs.erase(i);
			if (i == (procs.end())) {
				break;
			}
		}
	}
}



void BaseEnemy::paused()
{
	this->remainingAttackTime = this->clock.restart() + this->remainingAttackTime ;
}

void BaseEnemy::Continue()
{
	this->clock.restart();
}
