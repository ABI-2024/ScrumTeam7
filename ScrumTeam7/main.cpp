// ScrumTeam7.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Window.h"

#include "Menu.h"

#include "Actors.h"

#include "Rectangle.h"


int main()
{
    GameWindow::createWindow();

    TestAmmo::LoadTexture();
    TestTower::LoadTexture();
    TestEnemy::LoadTexture();

    Actors* actors;


    bool active = 0;
    bool paused = 1;

    while (Window.isOpen()) {
        switch (Menu::openMenu()) {
        case 1:

            active = 1;
            paused = 0;

            Rectangle* pRectangle;
            pRectangle = new Rectangle(80, 48);

            actors = new Actors();

            actors->initializeEnemy(1, { 0.f , 0.f });

            while (GameWindow::getWindow().isOpen() && active) {

                while (GameWindow::getWindow().pollEvent(GameEvent)) {
                    switch (GameEvent.type)
                    {

                    case sf::Event::Closed:
                        GameWindow::getWindow().close();
                        break;

                    case sf::Event::KeyPressed:
                        if (GameEvent.key.code == sf::Keyboard::Escape) {
                            //paused = !paused;
                            active = false;
                        }
                        break;

                    case sf::Event::MouseButtonPressed:

                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                            // Ermittlung der TilePosition
                            sf::Vector2i mousePos = sf::Mouse::getPosition(GameWindow::getWindow());

                            if (mousePos.x % 160 >= 80) {
                                mousePos.x += 80;
                            }
                            if (mousePos.y % 142 >= 71) {
                                mousePos.y += 67;
                            }

                            mousePos.x = (mousePos.x - 160) / 160;
                            mousePos.y = (mousePos.y - 135) / 142;

                            // Spawnt Tower
                            actors->initializeTower(1, sf::Vector2f(mousePos));
                        }
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                            // Ermittlung der TilePosition
                            sf::Vector2i mousePos = sf::Mouse::getPosition(GameWindow::getWindow());

                            if (mousePos.x % 160 >= 80) {
                                mousePos.x += 80;
                            }
                            if (mousePos.y % 142 >= 71) {
                                mousePos.y += 67;
                            }

                            mousePos.x = (mousePos.x - 160) / 160;
                            mousePos.y = (mousePos.y - 135) / 142;

                            // Spawnt Enemy
                            actors->initializeEnemy(1, sf::Vector2f(mousePos));
                        }

                        break;

                    default:
                        break;
                    }
                }

                if (!paused) {
                    actors->updateActors();

                    actors->Collisions();
                }

                GameWindow::getWindow().clear();

                actors->renderActors();
                for (int yA = 1; yA <= 5; yA++) {
                    for (int xA = 1; xA <= 8; xA++) {
                        pRectangle->setRectanglePosition(xA, yA);
                        pRectangle->render();
                    }
                }
                GameWindow::getWindow().display();

            }

            delete actors;

        case 2:
            break;
        case 0: default:
            Window.close();
            break;
        }
    }


    

    TestAmmo::unLoadTexture();
    TestTower::unLoadTexture();
    TestEnemy::unLoadTexture();

    GameWindow::deleteWindow();
    return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
