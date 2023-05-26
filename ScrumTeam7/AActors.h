#pragma once

#include <vector>

#include "Entity.h"
#include "enums.h"

class AActors
{
//private:
public:
// Beinhält alle Entities
	static std::vector<Entity*>* entities;

	/*
		Speziefische Unterscheidung von Entities in verschiedene Typen
		für schnellere und einfachere nutztnung von Collisionsfunktion.
	*/
	static std::vector<Entity*>* ally;
	static std::vector<Entity*>* allyAmmo;
	static std::vector<Entity*>* enemies;


	static void clearSeprateVectors(std::vector<Entity*>*, Entity*);
public:

	// Construkter wird gerupfen, bevor die Static-Funktionen benutzt werden .
	AActors();
	// Destruktor wird gerupfen, wenn diese Klasse nicht mehr benötigt wird.
	~AActors();

	static void create(const AllyType&,		const sf::Vector2f&);
	static void create(const AmmoType&,	const sf::Vector2f&);
	static void create(const EnemyType&,	const sf::Vector2f&);

	static void destroy(Entity*);

	static Entity* CollisionSingle(Entity*, const CollisionType&);
	static std::vector<Entity*>* CollisionPoly(Entity*, const CollisionType&);

	static void updateEntities();
	static void renderEntities();

	//static void pauseEntities();
	//static void continueEntities();
};

