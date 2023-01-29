#pragma once
#include <string>
#include <vector>


// Tower / Lehrer
#include "TestTower.h"

// Ammo / Geschosse
#include "TestAmmo.h"

// Enemies / Gegener
#include "TestEnemy.h"

// Money / Geld
#include "Geld.h"

/*
	Diese Klasse enthält alle Tower-,Enemies- und Ammotypen
	
	Sie kann die oben Genannten Klassen
		- updaten
		- Collidieren
		- rendern

	ToDo:

*/


class Actors
{
private:


	sf::Text text;
	// Speicher alle Klassentypnummern
	enum TowerType
	{
		TypeTestTower = 1
	};
	enum AmmoType
	{
		TypeTestAmmo = 1
	};
	enum EnemyType
	{
		TypeTestEnemy = 1
	};

	// Money / Geld
	Geld testGeld;

	// Alle vectoren von Tower / Lehrer
	std::vector<TestTower> testTower;

	// Alle vectoren von Ammo / Geschosse
	std::vector<TestAmmo> testAmmo;

	// Alle vectoren von Enemies / Gegener
	std::vector<TestEnemy> testEnemy;


	// Alle vectoren mit den BasisTypen* der Klassen
	std::vector<BaseTower*> Towers;
	std::vector<BaseAmmo*> Ammos;
	std::vector<BaseEnemy*> Enemies;

	// Updaten alle vectoren und ihre zugehörigen BasisTypen*
	void updateTowers();
	void updateAmmos();
	void updateEnemies();

	// Sorgt für Collision von den Klassen
	void CollisionEnemyWithTower();
	void CollisionAmmoWithEnemy();

	// Rendert alle Klassen
	void renderTowers();
	void renderAmmos();
	void renderEnemies();
	void renderMoney();
public:
	Actors();
	~Actors();
	// Ruft alle Update-Methoden
	void updateActors();

	// Ruft alle Collisions-Methoden
	void Collisions();

	// Ruft alle Render-Methoden
	void renderActors();

	// Gibt die Liste der Enemys zurück
	std::vector<BaseEnemy*>* getEnemy();

	// Initialisiert die Klassen
	void initializeTower(int TowerType, sf::Vector2f TilePosition);
	void initializeEnemy(int EnemyType, sf::Vector2f TilePosition);

	void initializeAmmo(int AmmoType, sf::Vector2f TowerPosition); // Beachte Parametername des Vectors

};

