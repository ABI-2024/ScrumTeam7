#include "Test_Level.h"
#include "Window.h"
#include "Raster.h"
#include <list>

#include <iostream>

sf::Vector2f Test_Level::TileSelection()
{
    sf::Vector2i mousePos = sf::Vector2i(Window.mapPixelToCoords(sf::Mouse::getPosition(Window)));

    mousePos -= {400, 200};

    if (mousePos.x > 0) {
        if (mousePos.x % 150 >= 150 / 2) {
            mousePos.x += 150;
        }
    }
    else {
        if (mousePos.x % 150 <= -150 / 2) {
            mousePos.x -= 150;
        }
    }

    if (mousePos.y % 150 >= 150 / 2) {
        mousePos.y += 150;
    }
    else {
        if (mousePos.y % 150 <= -150 / 2) {
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
        paused = false;
        actors.ContinueActors();
        break;
    case 1:

        break;
    case 2:
        active = false;
        break;
    default:
        break;
    }
}

Test_Level::Test_Level()
    : active(true) , paused(false) {}

Test_Level::~Test_Level()
{
}

void Test_Level::startLevel()
{
    for (int i = 0; i < 1; i++)
        actors.initializeEnemy(EnemyType::TestEnemy, { 0.f , 0.f });

    Raster raster(80,48);

    sf::Vector2f pos;

    int b = 0;
    sf::Texture back;
    back.loadFromFile("resource/Textures/Background_Sporthalle.png");

    sf::RectangleShape background;
    background.setSize(GameWindow::getMainView().getSize());
    background.setPosition(0.f , 0.f);
    background.setTexture(&back ,0);

    raster.offset = 50;
    

    sf::RectangleShape selecteionRectangle[2];
    selecteionRectangle[0].setSize({ GameWindow::getMainView().getSize().x, 150.f });
    selecteionRectangle[0].setOrigin( 0.f,selecteionRectangle[0].getSize().y/2.f);
    selecteionRectangle[1].setSize({ 150.f, GameWindow::getMainView().getSize().y });
    selecteionRectangle[1].setOrigin( selecteionRectangle[1].getSize().x / 2.f, 0.f );
    for (int i = 0; i < 2; i++) {
        selecteionRectangle[i].setFillColor(sf::Color(127, 127, 127, 64));
    }



    GameWindow::updateDeltaTime();

    while (GameWindow::getWindow().isOpen() && active) {

        GameWindow::updateDeltaTime();
        
        while (GameWindow::getWindow().pollEvent(GameEvent)) {
            switch (GameEvent.type)
            {

            case sf::Event::Closed:
                GameWindow::getWindow().close();
                break;

            case sf::Event::KeyPressed:
                

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

                        // Spawnt Tower
                        actors.initializeTower(TowerType::TestTower, this->TileSelection());
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

        if (!paused) {
            actors.updateActors();

            actors.Collisions();
        }
        else {
            menu.update();
        }



        Window.clear();

        Window.draw(background);

        for (int yA = 0; yA < 5; yA++) {
            for (int xA = 0; xA < 8; xA++) {
                raster.setRasterPosition(xA, yA);
                //raster.render();
            }
        }

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
