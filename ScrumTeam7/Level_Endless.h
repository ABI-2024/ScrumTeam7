#pragma once

#include "Level.h"

#include "InfinityWellen.h"


class Level_Endless : public Level
{
private:
	InfinityWellen iWellen;

	sf::Texture backgroundTexture2;

	sf::Clock backgroundTimer;
public:
	Level_Endless();
	virtual ~Level_Endless();

	void start(std::string  , Progression&) override;
};

