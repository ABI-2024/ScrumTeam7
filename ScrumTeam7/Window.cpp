
#include "Window.h"

#include <iostream>
#include <fstream>
#include <string>


// Static Variablen

Settings GameWindow::settings;

sf::RenderWindow* GameWindow::window = nullptr;

sf::Event GameWindow::ev;
sf::View GameWindow::mainView(sf::Vector2f(800, 450),sf::Vector2f(1600,900));

sf::Clock GameWindow::deltaTimer;
float GameWindow::deltaTime = 0;

// Helfer Funktionen
void writeToFile( const Settings& settings) {

    std::ofstream FILE("resource/Data/WindowSettings.csv");

    FILE << true << '\n';

    FILE << settings.WindowSize.x << ';'
        << settings.WindowSize.y << ';'
        << settings.Fullscreen << ';'

        << settings.FrameRateLimit << ';'

        << settings.MasterVolume << ';'
        << settings.SoundVolume << ';'
        << settings.MusicVolume << ";\n";

    FILE.close();

}

void readFromFile(Settings& settings) {

    std::ifstream FILE("resource/Data/WindowSettings.csv");

    if (!FILE.is_open()) {
        std::ofstream create("resource/Data/WindowSettings.csv");
        create << false << '\n';
        create.close();
        return;
    }

    std::string tmp;

    std::getline(FILE,tmp, '\n');
    if (std::stoi(tmp)) {

        std::getline(FILE, tmp, ';');
        settings.WindowSize.x = std::stoi(tmp);
        std::getline(FILE, tmp, ';');
        settings.WindowSize.y = std::stoi(tmp);
        std::getline(FILE, tmp, ';');
        settings.Fullscreen = std::stoi(tmp);

        std::getline(FILE, tmp, ';');
        settings.FrameRateLimit = std::stoi(tmp);

        std::getline(FILE, tmp, ';');
        settings.MasterVolume = std::stoi(tmp);
        std::getline(FILE, tmp, ';');
        settings.SoundVolume = std::stoi(tmp);
        std::getline(FILE, tmp, ';');
        settings.MusicVolume = std::stoi(tmp);
    }
    FILE.close();
}

// Window
void GameWindow::openWindow()
{
    readFromFile(settings);

    sf::ContextSettings set;
    set.antialiasingLevel = 16;

    if (window != nullptr) {
        delete window;
    }

    if (settings.Fullscreen) {
        window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Get F'd", sf::Style::Fullscreen, set);
    }
    else {
        window = new sf::RenderWindow(sf::VideoMode(settings.WindowSize.x, settings.WindowSize.y), "Get F'd", sf::Style::Titlebar | sf::Style::Close, set);
    }
    window->setFramerateLimit(settings.FrameRateLimit);
}

void GameWindow::closeWindow()
{
    delete window;
    window = nullptr;
}

sf::RenderWindow& GameWindow::getWindow()
{
    return *window;
}


// Settings
const Settings* GameWindow::getSettings() {
    return &settings;
}

void  GameWindow::setSettings(const Settings& newSettings) {
    settings = newSettings;
    writeToFile( settings  );
    openWindow();
}


// Event
sf::Event& GameWindow::getEvent()
{
    return ev;
}


// View
sf::View& GameWindow::getMainView()
{
    return mainView;
}


// DeltaTime Methoden
void GameWindow::updateDeltaTime()
{
    deltaTime = deltaTimer.restart().asSeconds();
}

const float& GameWindow::getDeltaTime()
{
    return deltaTime;
}