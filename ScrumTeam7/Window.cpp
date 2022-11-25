
#include "Window.h"


// Static Variablen

sf::ContextSettings* GameWindow::settings = nullptr;

sf::RenderWindow* GameWindow::window = nullptr;
unsigned int GameWindow::framerateLimit = 30;

sf::Event* GameWindow::ev = nullptr;






void GameWindow::createWindow()
{
    if (window == nullptr) {
        settings = new sf::ContextSettings;

        window = new sf::RenderWindow(sf::VideoMode(1600, 900), "Game", sf::Style::Titlebar | sf::Style::Close, *settings);
        window->setFramerateLimit(framerateLimit);

        ev = new sf::Event;
    }
}

void GameWindow::deleteWindow()
{
    delete window;
    window = nullptr;

    delete settings;
    settings = nullptr;

    delete ev;
    ev = nullptr;
}

// static Methoden
sf::RenderWindow& GameWindow::getWindow()
{
    return *window;
}

unsigned int GameWindow::getFramerateLimit()
{
    return framerateLimit;
}

void GameWindow::setFramerateLimit(unsigned int FramerateLimit)
{
    if (window != nullptr) {
        window->setFramerateLimit(FramerateLimit);
        framerateLimit = FramerateLimit;
    }
}

void GameWindow::setWindowSize(sf::Vector2u& WindowSize)
{
    if (window != nullptr) {
        delete window;
    } 
    window = new sf::RenderWindow(sf::VideoMode(WindowSize.x, WindowSize.y), "Game", sf::Style::Titlebar | sf::Style::Close, *settings);
   
}

sf::ContextSettings GameWindow::getWindowSettings()
{
    return *settings;
}

void GameWindow::setWindowSettings(sf::ContextSettings Settings)
{
    *settings = Settings;
}

sf::Event& GameWindow::getEvent()
{
    return *ev;
}

