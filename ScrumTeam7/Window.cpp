
#include "Window.h"


// Static Variablen
unsigned int GameWindow::framerateLimit = 30;

sf::RenderWindow* GameWindow::window = nullptr;


// constructor & destructor
GameWindow::GameWindow()
{
    if (window == nullptr) {

        window = new sf::RenderWindow(sf::VideoMode(1600,800), "Game", sf::Style::Default);
        window->setFramerateLimit(framerateLimit);
    }
}

GameWindow::~GameWindow()
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

void GameWindow::setWindowSettings()
{
}
