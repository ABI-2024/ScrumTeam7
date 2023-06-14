#pragma once

#include "BaseAmmo.h"

class RELI_Ammo : public BaseAmmo
{
private:
	static AmmoType ammoType;

	static sf::Texture* texture;
	static sf::Vector2f dir;			// Richtung und Geschwindigkeit des Projektils

	sf::Vector2f startPosition;		// StartPosition für reichweiten berechnung
	int enemiesHit;						// Anzahl der Gegner, die von einem Projektil getroffen werden können

public:
	static void LoadTexture();		// laden der Texturen
	static void unLoadTexture();	// entladen der Texturen

	RELI_Ammo(sf::Vector2f TowerPosition);
	virtual ~RELI_Ammo();

	void move();

	void update() override;
};

