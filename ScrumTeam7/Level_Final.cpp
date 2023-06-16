#include "Level_Final.h"
#include "Window.h"

#include <istream>


void Level_Final::readFile()
{
    std::ifstream stream("resource/Data/Dialog_2.txt");
    std::string tmp;
    int anzahl = 0, who = 0;

    std::getline(stream, tmp, '\n');
    anzahl = std::stoi(tmp);

    for (int i = 0; i < anzahl; i++) {
        std::getline(stream, tmp, ';');
        who = stoi(tmp);
        std::getline(stream, tmp, '\n');
        dialoge.push_back({ who, tmp });
    }

}

bool Level_Final::fillText(std::string* names, sf::Text* name, sf::Text* texte, int& dialogIndex, float textWigth)
{
    // string.find() string.copy
    size_t found = 0, offset = 0;
    int currentStr = 0;
    std::string str[3], helpStr;
    sf::Text help;

    help.setFont(font);
    help.setCharacterSize(40);

    if (dialogIndex >= dialoge.size()) {
        return false;
    }

    name->setString(names[dialoge[dialogIndex].who]);


    while (found < dialoge[dialogIndex].text.size() && offset != dialoge[dialogIndex].text.npos) {

        found = dialoge[dialogIndex].text.find(' ', found);

        helpStr = dialoge[dialogIndex].text.substr(offset, found - offset);

        help.setString(str[currentStr] + helpStr);

        if (help.getGlobalBounds().width > textWigth) {

            currentStr++;

            if (currentStr < 3) {
                str[currentStr].append(helpStr.substr(1, helpStr.npos));
            }
            else {
                return false;
            }


        }
        else {
            str[currentStr].append(helpStr);
        }
        offset = found;
        found++;
    }

    for (int i = 0; i < 3; i++) {
        texte[i].setString(str[i]);
    }

    dialogIndex++;
    return true;

}

void Level_Final::dialogWindow()
{
    readFile();

    bool dialog = true;
    int dialogIndex = 0;

    // Name der Figuren
    std::string names[5];
    names[0] = "Herr Berto";
    names[1] = "Frau Abel";
    names[2] = "Frau Herzmann";
    names[3] = "Herr Roed";
    names[4] = "Herr Huan";

    // Texturen der sprechenden Figuren
    sf::Texture textures[5];
    textures[0].loadFromFile("resource/Textures/Lehrer/SP/SP-Lehrer.png");
    textures[1].loadFromFile("resource/Textures/Lehrer/DE/DE-Lehrer.png");
    textures[2].loadFromFile("resource/Textures/Lehrer/BIO/BIO-Lehrer.png");
    textures[3].loadFromFile("resource/Textures/Lehrer/PH/PH-Lehrer.png");
    textures[4].loadFromFile("resource/Textures/Lehrer/MA/MA-Lehrer.png");

    // Alle Figuren und ihre größen
    sf::RectangleShape figures[5];
    figures[0].setSize({ 75.f,150.f });
    figures[0].setOrigin(figures[0].getSize() / 2.f);
    figures[0].setFillColor(sf::Color(100, 100, 100));

    figures[1] = figures[0];
    figures[2] = figures[0];
    figures[3] = figures[0];
    figures[4] = figures[0];

    figures[0].setTexture(&textures[0], 0);
    figures[0].setPosition({ 200.f ,GameWindow::getMainView().getSize().y / 2.f });

    figures[1].setTexture(&textures[1], 0);
    figures[1].setPosition({ 1000.f ,GameWindow::getMainView().getSize().y / 2.f });

    figures[2].setTexture(&textures[2], 0);
    figures[2].setPosition({ 400.f ,GameWindow::getMainView().getSize().y / 2.f });

    figures[3].setTexture(&textures[3], 0);
    figures[3].setPosition({ 800.f ,GameWindow::getMainView().getSize().y / 2.f });

    figures[4].setTexture(&textures[4], 0);
    figures[4].setPosition({ 600.f ,GameWindow::getMainView().getSize().y / 2.f });


    // Größe und aussehen des Textfeldes
    sf::RectangleShape textfeld;

    textfeld.setPosition({ GameWindow::getMainView().getSize().x / 2.f, GameWindow::getMainView().getSize().y * 3 / 4 });
    textfeld.setSize({ GameWindow::getMainView().getSize().x - 50.f, 300.f });
    textfeld.setOrigin(textfeld.getSize() / 2.f);
    textfeld.setOutlineThickness(10.f);

    textfeld.setFillColor(sf::Color(55, 148, 110));
    textfeld.setOutlineColor(sf::Color(102, 57, 49));

    // Alle drei Reihen von Texten in die später geschrieben wird
    sf::Font fontText;
    fontText.loadFromFile("resource/fonts/arial.ttf");

    sf::Text name;

    name.setFont(fontText);
    name.setCharacterSize(40);
    name.setFillColor(sf::Color::White);
    name.setPosition(textfeld.getGlobalBounds().left + 50.f, textfeld.getPosition().y - 100);

    sf::Text texte[3];
    texte[0].setFont(fontText);
    texte[0].setCharacterSize(40);
    texte[0].setFillColor(sf::Color::White);

    texte[1] = texte[0];
    texte[2] = texte[0];

    texte[0].setPosition(textfeld.getGlobalBounds().left + 50.f, textfeld.getPosition().y - 50);
    texte[1].setPosition(textfeld.getGlobalBounds().left + 50.f, textfeld.getPosition().y);
    texte[2].setPosition(textfeld.getGlobalBounds().left + 50.f, textfeld.getPosition().y + 50);

    // Ausgrauen des Hintergrundbildes
    background.setFillColor(sf::Color(200, 200, 200));

    while (Window.isOpen() && dialog)
    {
        // Events
        while (Window.pollEvent(GameEvent)) {
            switch (GameEvent.type)
            {

            case sf::Event::Closed:
                GameWindow::getWindow().close();
                break;

            case sf::Event::KeyPressed:
            case sf::Event::MouseButtonPressed:

                // Dialog fortfahren
                if (!fillText(names, &name, texte, dialogIndex, textfeld.getSize().x - 50.f)) {
                    dialog = false;
                }
                else {
                    for (int i = 0; i < 5; i++) {
                        figures[i].setFillColor(sf::Color(100, 100, 100));
                        figures[i].setScale(1, 1);
                    }
                    if (dialogIndex - 1 < dialoge.size()) {
                        figures[dialoge[dialogIndex - 1].who].setFillColor(sf::Color(255, 255, 255));
                        figures[dialoge[dialogIndex - 1].who].setScale(1.5f, 1.5f);
                    }
                }
                break;

            default:
                break;
            }
        }

        // render
        Window.clear();

        Window.draw(background);

        Window.draw(figures[0]);
        Window.draw(figures[1]);
        Window.draw(figures[2]);
        Window.draw(figures[3]);
        Window.draw(figures[4]);

        Window.draw(textfeld);

        Window.draw(name);
        Window.draw(texte[0]);
        Window.draw(texte[1]);
        Window.draw(texte[2]);

        Window.display();
    }

    background.setFillColor(sf::Color(255, 255, 255));

}

void Level_Final::endLevel(bool isVictory)
{
    while (Window.isOpen() && active)
    {
        // Events
        while (Window.pollEvent(GameEvent)) {
            switch (GameEvent.type)
            {

            case sf::Event::Closed:
                GameWindow::getWindow().close();
                break;

            case sf::Event::KeyPressed:
                active = false;
                break;

            case sf::Event::MouseButtonPressed:
                active = false;
                break;

            default:
                break;
            }
        }

        Window.clear();

        Window.draw(endOfTheLevel);

        if (isVictory) {
            Window.draw(victory);
        }
        else {
            Window.draw(gameOver);
        }

        Window.display();
    }
}

Level_Final::Level_Final()
{
    timeToWin = sf::seconds(500);

	backgroundTexture.loadFromFile("resource/Textures/Level/Background-Lehrerzimmer.png");
	background.setTexture(&backgroundTexture, 0);
}

Level_Final::~Level_Final()
{
    dialogWindow();
}
