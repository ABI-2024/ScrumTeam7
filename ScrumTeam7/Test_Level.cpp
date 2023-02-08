#include "Test_Level.h"
#include "Window.h"
#include "Raster.h"
#include "Menu_Options.h"

#include <iostream>

sf::Vector2f Test_Level::TileSelection()
{
    // Hier wird die Tile-Position ermittelt
    sf::Vector2i mousePos = sf::Vector2i(Window.mapPixelToCoords(sf::Mouse::getPosition(Window)));

    mousePos -= {400, 200};

    if (mousePos.x > 0) {
        if (mousePos.x % 150 >= 75) {
            mousePos.x += 150;
        }
    }
    else {
        if (mousePos.x % 150 <= -75) {
            mousePos.x -= 150;
        }
    }

    if (mousePos.y % 150 >= 75) {
        mousePos.y += 150;
    }
    else {
        if (mousePos.y % 150 <= -75) {
            mousePos.y -= 150;
        }
    }

    mousePos.x = (mousePos.x) / 150;
    mousePos.y = (mousePos.y) / 150;

    return sf::Vector2f(mousePos);
}

void Test_Level::buttonEvents()
{
    switch ( this->menu.mouseClick()) {
    case 0:
        // Spiel geht weiter
        paused = false;
        actors.ContinueActors();
        break;
    case 1:
        // Optionsmenu wird ge�ffnet
        Menu_Options::openOptions();
        break;
    case 2:
        // Das Level wird verlassen
        active = false;
        break;
    default:
        break;
    }
}

Test_Level::Test_Level()
    : active(true) , paused(false) 
{
    back.loadFromFile("resource/Textures/Background_Sporthalle.png");

    background.setSize(GameWindow::getMainView().getSize());
    background.setPosition(0.f, 0.f);
    background.setTexture(&back, 0);


    selecteionRectangle[0].setSize({ GameWindow::getMainView().getSize().x, 150.f });
    selecteionRectangle[0].setOrigin(0.f, selecteionRectangle[0].getSize().y / 2.f);
    selecteionRectangle[1].setSize({ 150.f, GameWindow::getMainView().getSize().y });
    selecteionRectangle[1].setOrigin(selecteionRectangle[1].getSize().x / 2.f, 0.f);
    for (int i = 0; i < 2; i++) {
        selecteionRectangle[i].setPosition(4000.f, 4000.f);
        selecteionRectangle[i].setFillColor(sf::Color(127, 127, 127, 64));
    }
}

Test_Level::~Test_Level()
{
}

void Test_Level::startLevel()
{
    for (int i = 0; i < 1; i++)
        actors.initializeEnemy(EnemyType::TestEnemy, { 0.f , 0.f });

    sf::Vector2f pos;

    /*Raster raster(80, 48);
    raster.offset = 50;*/
    
    GameWindow::updateDeltaTime();

    while (Window.isOpen() && active) {

        GameWindow::updateDeltaTime();
        
        // Events
        while (Window.pollEvent(GameEvent)) {
            switch (GameEvent.type)
            {

            case sf::Event::Closed:
                GameWindow::getWindow().close();
                break;

            case sf::Event::KeyPressed:
                
                // Togglet Pausierung
                if (GameEvent.key.code == sf::Keyboard::Escape) {
                    if (paused) {
                        actors.ContinueActors();
                    }
                    else {
                        actors.pauseActors();
                    }
                    paused = !paused;
                }
                break;

            case sf::Event::MouseButtonPressed:
                if (!paused) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {                      

                        testShop.buttonEvents(actors, TileSelection());

                        //// Spawnt Tower
                        //actors.initializeTower(TowerType::TestTower, this->TileSelection());
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                        // Spawnt Enemy
                        actors.initializeEnemy(EnemyType::TestEnemy, this->TileSelection());
                    }
                }
                else {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        this->buttonEvents();
                    }
                }
                break;

            case sf::Event::MouseMoved:

                pos = this->TileSelection();
                if (pos.y >= 0 && pos.y <5 && pos.x >= 0 && pos.x <8) {
                    selecteionRectangle[0].setPosition(0.f, this->TileSelection().y * 150 + 200);
                    selecteionRectangle[1].setPosition(this->TileSelection().x * 150 + 400, 0.f);
                }
                else {

                    selecteionRectangle[0].setPosition(4000.f,4000.f);
                    selecteionRectangle[1].setPosition(4000.f,4000.f);
                }
                break;

            case sf::Event::LostFocus:
                if (!paused) {
                    actors.pauseActors();
                }
                paused = 1;

                break;

            default:
                break;
            }
        }

        // Updates
        if (!paused) {
            actors.updateActors();

            actors.Collisions();
        }
        else {
            menu.update();
        }


        // Render
        Window.clear();

        Window.draw(background);

        /*for (int yA = 0; yA < 5; yA++) {
            for (int xA = 0; xA < 8; xA++) {
                raster.setRasterPosition(xA, yA);
                raster.render();
            }
        }*/

        for (int i = 0; i < 2; i++) {
            Window.draw(selecteionRectangle[i]);
        }

        actors.renderActors();

        testShop.render();

        if (paused) {
            menu.render();
        }


        Window.display();

    }

}