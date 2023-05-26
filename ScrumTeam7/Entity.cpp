#include "Entity.h"

#include "Window.h"

// protected static Variables 
sf::Texture* Entity::shadowTexture = nullptr;


const CollisionType& Entity::getCollisionType()
{
	return CollisionType::non;
}

sf::FloatRect Entity::getHitBox()
{
	return body.getGlobalBounds();
}

Entity::Entity()
{
}

// Constructur & Destructur
Entity::Entity(sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size/2.f);
	body.setPosition(position);


}

Entity::~Entity()
{
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

void Entity::render()
{
	Window.draw(body);
}
