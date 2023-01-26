#include "Test_Level.h"
#include "Window.h"
#include <list>


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

                        // Ermittlung der TilePosition
                        sf::Vector2i mousePos = sf::Vector2i( Window.mapPixelToCoords(sf::Mouse::getPosition(Window)));

                        mousePos -= {320, 135};

                        if (mousePos.x % 160 >= 80) {
                            mousePos.x += 80;
                        }
                        if (mousePos.y % 135 >= 68) {
                            mousePos.y += 67;
                        }

                        mousePos.x = (mousePos.x) / 160;
                        mousePos.y = (mousePos.y) / 135;

                        // Spawnt Tower
                        actors.initializeTower(TowerType::TestTower, sf::Vector2f(mousePos));
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                        // Ermittlung der TilePosition
                        sf::Vector2i mousePos = sf::Vector2i(Window.mapPixelToCoords(sf::Mouse::getPosition(Window)));

                        if (mousePos.x % 160 >= 80) {
                            mousePos.x += 80;
                        }
                        if (mousePos.y % 135 >= 68) {
                            mousePos.y += 67;
                        }

                        mousePos.x = (mousePos.x - 160) / 160;
                        mousePos.y = (mousePos.y - 135) / 135;

                        // Spawnt Enemy
                        actors.initializeEnemy(EnemyType::TestEnemy, sf::Vector2f(mousePos));
                    }
                }
                else {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        this->buttonEvents();
                    }
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

        actors.renderActors();

        testShop.render();

        if (paused) {
            menu.render();
        }


        Window.display();

    }

}
