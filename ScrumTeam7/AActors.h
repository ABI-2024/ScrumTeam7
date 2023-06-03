#pragma once

#include <vector>

#include "Entity.h"
#include "enums.h"
class Wellen;
class AActors
{
	friend Wellen;
	// ------------------------------------------ for class Geld
private:

	static int collectedRevenue;
public:

	static int getCollectedRevenue();
	static void addCollectedRevenue(int);
	// ------------------------------------------ for class Geld

private:

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

	// Construkter wird gerufen, bevor die Static-Funktionen benutzt werden .
	AActors();
	// Destruktor wird gerufen, wenn diese Klasse nicht mehr benötigt wird.
	~AActors();

	static bool create(const AllyType&,		const sf::Vector2f&);
	static bool create(const AmmoType&,	const sf::Vector2f&);
	static bool create(const EnemyType&,	const sf::Vector2f&);

	static void destroy(Entity*);

	static Entity* CollisionSingle(sf::FloatRect, const CollisionType&);
	static std::vector<Entity*>* CollisionPoly(sf::FloatRect, const CollisionType&);

	static void updateEntities();
	static void renderEntities();

	static void pauseEntities();
	static void continueEntities();
};

