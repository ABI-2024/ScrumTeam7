// ScrumTeam7.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "enums.h"

#include "Menu.h"
#include "Menu_Options.h"

#include "Level_Selector.h"

#include "Music.h"


int main()
{
    // Erstellt das Fenster
    GameWindow::openWindow();

    // Setzt den View des Fensters
    // Bei uns ist dieser Statisch muss daher nicht verändert werden
    GameWindow::getMainView().setViewport({0,0,1,1});

    Level_Selector* selector = nullptr;

    // Spiel Ausführung
    while (Window.isOpen()) {

        // openMenu gibt einen Intergerwert zurück
        switch (Menu::openMenu()) {
        case 1: // Button Start

            selector = new Level_Selector();
            selector->openMenu();
            delete selector;
            selector = nullptr;
            
            break;
        case 2: // Button Optionen
            Menu_Options::openOptions();
            break;

        case 0: default:    // Exit
            Window.close();
            break;
        }
    }

    // Schlließt das Fenster
    GameWindow::closeWindow();

    // Alle geladene Music wird aus dem Arbeitsspeicher gelöscht
    Music::unloadMusic();

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
