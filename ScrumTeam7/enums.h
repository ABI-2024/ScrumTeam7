#pragma once


// Speicher alle Klassen-Typ-Nummern
enum class AllyType : char
{
	none = 0,
	TestTower,
	Mathelehrer,
	INF_Lehrer,
	EN_Lehrer,
	DE_Lehrer,
	METAL_Lehrer
};
enum class AmmoType : char
{
	none = 0,

	TestAmmo = 1,	
	Mathe = 2,
	Englisch_weak = 3,
	Englisch_medium = 4,
	Englisch_strong = 5,
	Englisch_strongest = 6,
	Inf_weak = 7,
	Inf_medium = 8,
	Inf_strong = 9,
	DE_Ammo,
	METAL_Ammo
};
enum class EnemyType : char
{
	none = 0,
	TestEnemy = 1,
	Nerd = 2,
	Steroidenking = 3
};
