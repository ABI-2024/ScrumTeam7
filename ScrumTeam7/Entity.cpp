#include "Entity.h"

#include "Window.h"

// public static Variables 
std::vector<Entity*> Entity::entities;


// protected static Variables 
sf::Texture* Entity::shadowTexture = nullptr;


// Constructur & Destructur
Entity::Entity()
{
	entities.push_back(this);
}

Entity::~Entity()
{
	for (auto i = entities.begin(); i != entities.end(); ++i) {
		if ((*i) == this) {
			entities.erase(i);
			break;
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
