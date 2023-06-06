#pragma once

#include "SFML/Graphics.hpp"

// Alle verschiedenen Statuseffekt-Typen
enum class StatusType {
	non = 0,
	burn,
	stun,
};


class StatusEffect
{
protected:
	StatusType type;		// Type
	sf::Time duration;		// Dauerdes Statuseffekts
	float strength;			// Stärke des Effekts

public:
	// Construktors
	StatusEffect(StatusType, int , float);
	StatusEffect(StatusType, sf::Time , float);

	// Destruktor
	~StatusEffect();

	// Get-Methoden
	StatusType getType();
};

