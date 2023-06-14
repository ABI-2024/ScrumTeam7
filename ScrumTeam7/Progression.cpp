#include "Progression.h"

#include <fstream>

#define filename "resource/Data/Progression-&-Highscore.txt"

void Progression::readFromFile()
{
    std::ifstream FILE( filename);

    if (!FILE.is_open()) {  // Wenn des nich geöffnet werden konnte wird eine neue Datei angelegt und aller fortschrit und Highscore geht verloren
        std::ofstream create("WindowSettings.csv");
        create << 0 << '\n';
        create << 0 << '\n';
        create.close();
        return;
    }

    std::string tmp; // wird gebaucht um aus der Datei zulessen

    ////  Daten aus der Datei werden in die Atribute von Progression

    // Level_Progression
    std::getline(FILE, tmp, '\n');  
    status = (Level_Progression)std::stoi(tmp);

    // Anzahl der Highscores
    std::getline(FILE, tmp, '\n');
    int i = std::stoi(tmp);

    // Beschriftung der aller Highscores aus der Datei
    std::string name;
    int score;

    for (; i > 0; i--) {
        std::getline(FILE, tmp, '\n');
        score = std::stoi(tmp);

        highscores.push_back(new Highscores(score));
    }

    FILE.close();
}

void Progression::writeToFile()
{
	std::ofstream FILE(filename);

    FILE << (int)status << '\n'; // Level_Progression

    FILE << highscores.size()<< '\n'; // Anzahl der Highscores

    for (int i = 0; i < highscores.size(); i++) { // Alle Highscores
        FILE <<highscores[i]->score<< '\n';
    }

	FILE.close();
}

Progression::Progression()
	:status(Level_Progression::FromStart)
{
    readFromFile();
}

Progression::~Progression()
{
    writeToFile();

	for (auto i = highscores.begin(); i != highscores.end(); i++) {
		delete (*i);
	}
}

void Progression::addScore(Highscores* score)
{
	highscores.push_back(score);
}

void Progression::updateProgession(const Level_Progression& nProgress)
{
	if (status < nProgress) {
		status = nProgress;
	}
}
