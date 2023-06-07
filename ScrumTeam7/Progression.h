#pragma once
#include <string>
#include <vector>

struct Highscores {
	std::string playerName;
	int score;

	Highscores(const std::string& playerName, const int& score)
		:playerName(playerName), score(score)
	{	}
};

enum class Level_Progression : char {
	FromStart = 0,
	Level_1,
	Level_2,
	Level_3,
	AllOnlocked,
} ;

class Progression
{
public:
	Level_Progression status;

	std::vector< Highscores*> highscores;

private:
	void readFromFile();
	void writeToFile();

public:
	Progression();
	~Progression();

	void addScore(Highscores*);
	void updateProgession(const Level_Progression&);

};

