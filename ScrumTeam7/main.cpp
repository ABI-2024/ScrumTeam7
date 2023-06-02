// ScrumTeam7.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "enums.h"

#include "Menu.h"
#include "TowerSelect.h"
#include "Menu_Options.h"

#include "Test_Level.h"
#include "Level_Selector.h"


int main()
{
    GameWindow::openWindow();

    GameWindow::getMainView().setViewport({0,0,1,1});

    Entity::loadTexture();

    TestAmmo::LoadTexture();
    MA_Ammo::LoadTexture();
    INF_Ammo::LoadTexture();
    EN_Ammo::LoadTexture();
    DE_Ammo::LoadTexture();
    METAL_Ammo::LoadTexture();

    TestTower::LoadTexture();
    Mathelehrer::LoadTexture();
    INF_Lehrer::LoadTexture();
    EN_Lehrer::LoadTexture();
    DE_Lehrer::LoadTexture();
    METAL_Lehrer::LoadTexture();
    

    TestEnemy::LoadTexture();
    Nerd::LoadTexture();
    Steroidenking::LoadTexture();

    Level_Selector* selector = nullptr;



    // 
    while (Window.isOpen()) {
        switch (Menu::openMenu()) {
        case 1:

            selector = new Level_Selector();
            selector->openMenu();
            delete selector;
            selector = nullptr;
            
            break;
        case 2:
            Menu_Options::openOptions();
            break;
        case 0: default:
            Window.close();
            break;
        }
    }

    
    Entity::unloadTexture();

    TestAmmo::unLoadTexture();
    MA_Ammo::unLoadTexture();
    INF_Ammo::unLoadTexture();
    EN_Ammo::unLoadTexture();
    DE_Ammo::unLoadTexture();
    METAL_Ammo::unLoadTexture();

    TestTower::unLoadTexture();
    Mathelehrer::unLoadTexture();
    INF_Lehrer::unLoadTexture();
    EN_Lehrer::unLoadTexture();
    DE_Lehrer::unLoadTexture();
    METAL_Lehrer::unLoadTexture();
    

    TestEnemy::unLoadTexture();
    Nerd::unLoadTexture();
    Steroidenking::unLoadTexture();

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
