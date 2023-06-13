#include "Entity.h"

#include "Window.h"
#include "Burn.h"
#include "Stun.h"
#include "Cripple.h"

// protected static Variables 
sf::Texture* Entity::shadowTexture = nullptr;

sf::FloatRect Entity::getHitBox()
{
	return body.getGlobalBounds();
}

void Entity::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos);
}

Entity::Entity()
	:statusprocs(nullptr)
{}

// Constructur & Destructur
Entity::Entity(sf::Vector2f size, sf::Vector2f position)
	: statusprocs(nullptr)
{
	body.setSize(size);
	body.setOrigin(size/2.f);
	body.setPosition(position);
}

Entity::~Entity()
{
	if (statusprocs != nullptr) {
		for (auto i = statusprocs->begin(); i != statusprocs->end(); i++) {
			delete (*i);
		}

		delete statusprocs;

	}
}

void Entity::takeDamage(float damage )
{

}

void Entity::addStatusEffect(StatusEffect effect)
{

	if (statusprocs != nullptr) { // wenn statusprocs == nullptr ist bedeutet das, dass dieser Entity keine StatusEffekte haben kann
		for (int i = 0; i < statusprocs->size(); i++) {
			if ((*statusprocs)[i]->getType() == effect.getType()) {
				return;
			}
				
		}
		
		switch (effect.getType())
		{

		case StatusType::burn:
			statusprocs->push_back( new Burn(effect, this) );
			break;
		case StatusType::stun:
			statusprocs->push_back(new Stun(effect, this));
			break;
		case StatusType::cripple:
			statusprocs->push_back(new Cripple(effect, this));
			break;
		default:
			break;
		}
	}
}


void Entity::updateStatusprocs(bool canWalk, bool canAttack)
{
	status.canWalk = canWalk;
	status.canAttack = canAttack;

	status.multi_Attackspeed = 1.f;
	status.multi_Damage = 1.f;
	status.multi_TakenDamage = 1.f;
	status.multi_WalkingSpeed = 1.f;


	if (statusprocs != nullptr) {  // wenn statusprocs == nullptr ist bedeutet das, dass dieser Entity keine StatusEffekte haben kann

		for (auto i = statusprocs->begin(); i != statusprocs->end(); i++) {


			if (!(*i)->isActive()) {
			redo:
				// löscht momentanes Element
				delete (*i);

				// löscht momentanes Element aus dem std::vector entities
				i = statusprocs->erase(i);

				// Abfrage ob der zurück gegebene iterator von erase das Ende des std::vectors ist
				if (i == statusprocs->end()) {
					break;
				}

				/*
				Abfrage ob der zurück gegebene iterator von erase ebenfalls ein nullptr ist
				und wenn ja wiederhole Vorgang.
				*/
				if (!(*i)->isActive()) {
					goto redo;
				}

			}

			(*i)->update();
		}

	}
}

// public static Methoden
void Entity::loadTexture()
{
	if (shadowTexture == nullptr) {
		shadowTexture = new sf::Texture();

		if (!shadowTexture->loadFromFile("resource/Textures/SchattenPersonen.png")) {
			shadowTexture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Entity::unloadTexture()
{
	delete shadowTexture;
	shadowTexture = nullptr;
}


// public Methoden
void Entity::renderShadow()
{
	Window.draw(shadow);
}

EntityStatus* Entity::getEntityStatus()
{
	return &status;
}

sf::Vector2f Entity::getPosition()
{
	return body.getPosition();
}

sf::Vector2f Entity::getTilePosition()
{
	return {-1,-1};
}

void Entity::render()
{
	Window.draw(body);
}

void Entity::pauseEntitiy()
{
}

void Entity::continueEntitiy()
{
}
