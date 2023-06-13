#pragma once

#include "Level.h"
#include <string>

struct Monolog {
	int who;
	std::string text;

	Monolog(int who, std::string text) {
		this->who = who;
		this->text = text;
	}
};

class Level_1 : public Level
{
private:

	std::vector<Monolog> dialoge;

	void readFile();
	bool fillText(std::string* names, sf::Text* name,sf::Text* texte, int& dialogIndex, float textWigth);
	void dialogWindow();
public:
	Level_1();
	virtual ~Level_1();
};

