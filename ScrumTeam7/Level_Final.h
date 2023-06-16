#pragma once

#include "Level.h"
#include "Level_1.h"
#include "Music.h"

class Level_Final : public Level
{
	std::vector<Monolog> dialoge;

	void readFile();
	bool fillText(std::string* names, sf::Text* name, sf::Text* texte, int& dialogIndex, float textWigth);
	void dialogWindow();

	void endLevel(bool isVictory) override;
public:
	Level_Final();
	virtual ~Level_Final();
};

