
#include "Window.h"


// Static Variablen

sf::ContextSettings GameWindow::settings;

sf::RenderWindow* GameWindow::window = nullptr;
unsigned int GameWindow::framerateLimit = 30;

sf::Event GameWindow::ev;
sf::View GameWindow::mainView;





void GameWindow::openWindow()
{
    if (window != nullptr) {
        delete window;
    }
    window = new sf::RenderWindow(sf::VideoMode(1600, 900), "Game", sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(framerateLimit);
}

void GameWindow::openWindow(const sf::Vector2u& WindowSize)
{

    if (window != nullptr) {
        delete window;
    }
    window = new sf::RenderWindow(sf::VideoMode(WindowSize.x,WindowSize.y), "Game", sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(framerateLimit);
}

void GameWindow::openFullscreen()
{
    if (window != nullptr) {
        delete window;
    }
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen, settings);
    window->setFramerateLimit(framerateLimit);
}

void GameWindow::closeWindow()
{
    delete window;
    window = nullptr;
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

void GameWindow::setFramerateLimit(const unsigned int& FramerateLimit)
{
    if (window != nullptr) {
        window->setFramerateLimit(FramerateLimit);
        framerateLimit = FramerateLimit;
    }
}

sf::ContextSettings GameWindow::getWindowSettings()
{
    return settings;
}

void GameWindow::setWindowSettings(const sf::ContextSettings& Settings)
{
    settings = Settings;
}

sf::Event& GameWindow::getEvent()
{
    return ev;
}

sf::View& GameWindow::getMainView()
{
    return mainView;
}

