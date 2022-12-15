// ScrumTeam7.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "enums.h"

#include "Menu.h"

#include "Test_Level.h"


int main()
{
    GameWindow::openWindow();

    GameWindow::getMainView().setSize(1600,900);
    GameWindow::getMainView().setViewport({0,0,1,1});

    TestAmmo::LoadTexture();
    TestTower::LoadTexture();
    TestEnemy::LoadTexture();

    Test_Level* level;


    while (Window.isOpen()) {
        switch (Menu::openMenu()) {
        case 1:

            level = new Test_Level;

            level->startLevel();

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

    GameWindow::closeWindow();
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
