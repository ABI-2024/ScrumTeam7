// ScrumTeam7.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Window.h"
#include "TestTower.h"
#include "TestEnemy.h"


int main()
{
    GameWindow window;
    sf::Event ev;

    TestAmmo::LoadTexture();
    TestTower::LoadTexture();
    TestEnemy::LoadTexture();

    TestTower tower(sf::Vector2f(0.f,0.f));
    TestEnemy enemy(0.f);

    while (GameWindow::getWindow().isOpen()) {

        while (GameWindow::getWindow().pollEvent(ev) ) {
            switch (ev.type)
            {
            case sf::Event::Closed:
                GameWindow::getWindow().close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape) {
                    GameWindow::getWindow().close();
                }
                break;

            default:
                break;
            }
        }


        tower.update();
        enemy.update();


        GameWindow::getWindow().clear();

        tower.render();
        enemy.render();

        GameWindow::getWindow().display();

    }

    TestAmmo::unLoadTexture();
    TestTower::unLoadTexture();
    TestEnemy::unLoadTexture();

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
