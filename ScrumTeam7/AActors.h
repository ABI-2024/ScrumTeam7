#pragma once

#include <vector>

#include "Entity.h"
#include "enums.h"
class Wellen;
class AActors
{
	// ------------------------------------------ Nebenfuktion
	friend Wellen;
private:

	static int collectedRevenue;
public:

	static int getCollectedRevenue();
	static void addCollectedRevenue(int);
	// ------------------------------------------ Nebenfuktion

	// ------------------------------------------ Hauptfunktion
private:

	// Beinh�lt alle Entities
	static std::vector<Entity*>* entities;

	/*
		Speziefische Unterscheidung von Entities in verschiedene Typen
		f�r schnellere und einfachere nutztnung von Collisionsfunktion.
	*/
	static std::vector<Entity*>* ally;
	static std::vector<Entity*>* allyAmmo;
	static std::vector<Entity*>* enemies;

	// L�scht die �bergebene Adreese aus dem �bergebenen std::vector
	static void clearSeprateVectors(std::vector<Entity*>*, Entity*);
public:

	// Construkter wird gerufen, bevor die Static-Funktionen benutzt werden .
	AActors();
	// Destruktor wird gerufen, wenn diese Klasse nicht mehr ben�tigt wird.
	~AActors();

	// Diese Funktionen inizalisieren die verschiedenen Entities
	static bool create(const AllyType&,		const sf::Vector2f&);
	static bool create(const AmmoType&,	const sf::Vector2f&);
	static bool create(const EnemyType&,	const sf::Vector2f&);

	// Diese Funktion l�sst es zu das Entities "selbst zerst�ren"/ "selbst" l�schen k�nnen
	static void destroy(Entity*);

	// Diese Funktion gibt das Erste gefundene Entity zur�ck, welches mit der Hitbox(sf::FloatRect) �berlappt
	static Entity* CollisionSingle(sf::FloatRect, const CollisionType&);
	// Diese Funktion gibt alle gefundenen Entities zur�ck, welche mit der Hitbox(sf::FloatRect) �berlappen
	static std::vector<Entity*>* CollisionPoly(sf::FloatRect, const CollisionType&);

	// called alle update-Funktionen aller Entities
	static void updateEntities();
	// called alle render-Funktionen aller Entities
	static void renderEntities();

	// Diese Funktonen sind zum Stoppen und fortfahren aller sf::Clock aller Entities
	static void pauseEntities();
	static void continueEntities();

	// ------------------------------------------ Hauptfunktion
};

