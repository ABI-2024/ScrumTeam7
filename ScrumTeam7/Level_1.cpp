#include "Level_1.h"
#include "Window.h"

#include <istream>

void Level_1::readFile()
{
    std::ifstream stream("resource/Data/Dialog_1.txt");
    std::string tmp;
    int anzahl = 0,who = 0;

    std::getline(stream, tmp, '\n');
    anzahl = std::stoi(tmp);

    for (int i = 0; i < anzahl; i++) {
        std::getline(stream, tmp, ';');
        who = stoi(tmp);
        std::getline(stream, tmp, '\n');
        dialoge.push_back({ who, tmp });
    }

}

bool Level_1::fillText(std::string* names, sf::Text* name, sf::Text* texte, int& dialogIndex, float textWigth)
{
    // string.find() string.copy
    size_t found = 0, offset= 0;
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

        helpStr =dialoge[dialogIndex].text.substr(offset, found-offset);

        help.setString(str[currentStr]+ helpStr);

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

void Level_1::dialogWindow()
{
    readFile();

	bool dialog = true;
	int dialogIndex = 0;

    // Name der Figuren
    std::string names[4];
    names[0] = "King F.";
    names[1] = "Standartschueler";
    names[2] = "Herr Berto";
    names[3] = "Klasse";

    // Texturen der sprechenden Figuren
    sf::Texture textures[4];
    textures[0].loadFromFile("resource/Textures/Schueler/Steroidenking.png");
    textures[1].loadFromFile("resource/Textures/Schueler/STD-Student-m.png");
    textures[2].loadFromFile("resource/Textures/Lehrer/SP/SP-Lehrer.png");
    textures[3].loadFromFile("resource/Textures/Schueler/Klasse.png");

    // Alle Figuren und ihre größen
    sf::RectangleShape figures[4];
    figures[0].setSize({75.f,150.f});
    figures[0].setOrigin(figures[0].getSize()/2.f);
    figures[0].setFillColor(sf::Color(100,100,100));

    figures[1] = figures[0];
    figures[2] = figures[0];
    figures[3] = figures[0];


    figures[3].setSize({ 75.f*3.f, 75.f* 3.f });
    figures[3].setOrigin(figures[3].getSize() / 2.f);

    figures[0].setTexture(&textures[0],0);
    figures[0].setPosition({ 1100.f ,GameWindow::getMainView().getSize().y / 2.f});

    figures[1].setTexture(&textures[1],0);
    figures[1].setPosition({ 1200.f ,GameWindow::getMainView().getSize().y / 2.f });

    figures[2].setTexture(&textures[2],0);
    figures[2].setPosition({ 400.f ,GameWindow::getMainView().getSize().y / 2.f });

    figures[3].setTexture(&textures[3],0);
    figures[3].setPosition({ 1350.f ,GameWindow::getMainView().getSize().y / 2.f });


    // Größe und aussehen des Textfeldes
    sf::RectangleShape textfeld;

    textfeld.setPosition({ GameWindow::getMainView().getSize().x/2.f, GameWindow::getMainView().getSize().y * 3/4});
    textfeld.setSize({ GameWindow::getMainView().getSize().x-50.f, 300.f });
    textfeld.setOrigin(textfeld.getSize()/2.f);
    textfeld.setOutlineThickness(10.f);

    textfeld.setFillColor(sf::Color(55,148,110));
    textfeld.setOutlineColor(sf::Color(102,57,49));

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

    texte[0].setPosition(textfeld.getGlobalBounds().left + 50.f, textfeld.getPosition().y-50);
    texte[1].setPosition(textfeld.getGlobalBounds().left + 50.f, textfeld.getPosition().y);
    texte[2].setPosition(textfeld.getGlobalBounds().left + 50.f, textfeld.getPosition().y+50);

    // Ausgrauen des Hintergrundbildes
    background.setFillColor(sf::Color(200,200,200));

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
                if (!fillText(names,&name,texte, dialogIndex, textfeld.getSize().x -50.f )) {
                    dialog = false;
                }
                else {
                    for (int i = 0; i < 4; i++) {
                        figures[i].setFillColor(sf::Color(100, 100, 100));
                        figures[i].setScale(1, 1);
                    }
                    if (dialogIndex-1 < dialoge.size()) {
                        figures[dialoge[dialogIndex-1].who].setFillColor(sf::Color(255, 255, 255));
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

        Window.draw(textfeld);

        Window.draw(name);
        Window.draw(texte[0]);
        Window.draw(texte[1]);
        Window.draw(texte[2]);

        Window.display();
    }

    background.setFillColor(sf::Color(255, 255, 255));

}

Level_1::Level_1()
{

	backgroundTexture.loadFromFile("resource/Textures/Level/Background-Tutorial-3.png");
	background.setTexture(&backgroundTexture,0);

    dialogWindow();
}

Level_1::~Level_1()
{
}
