#include "Level_Endless.h"

#include "Window.h"
#include "Menu_Options.h"
#include "Randomizer.h"

#include "Music.h"


Level_Endless::Level_Endless()
{
    backgroundTexture.loadFromFile("resource/Textures/Level/Background_Sporthalle.png");
    backgroundTexture2.loadFromFile("resource/Textures/Level/Background-Lehrerzimmer.png");

    background.setTexture(&backgroundTexture, 0);
}

Level_Endless::~Level_Endless()
{
}

void Level_Endless::start(std::string filename)
{


    Music::startMusic();

    shop.setKarten(TowerSelect::openTowerSelect());


    sf::Vector2f pos;

    GameWindow::updateDeltaTime();

    while (Window.isOpen() && active) {

        GameWindow::updateDeltaTime();

        iWellen.update(geld);

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
                        AActors::continueEntities();
                    }
                    else {
                        AActors::pauseEntities();
                    }
                    paused = !paused;
                }
                break;

            case sf::Event::MouseButtonPressed:
                if (!paused) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                        shop.buttonEvents(TileSelection());
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                        // Spawnt Enemy
                        AActors::create(EnemyType::TestEnemy, this->TileSelection());
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
                if (pos.y >= 0 && pos.y < 5 && pos.x >= 0 && pos.x < 8) {
                    selecteionRectangle[0].setPosition(0.f, this->TileSelection().y * 150 + 200);
                    selecteionRectangle[1].setPosition(this->TileSelection().x * 150 + 400, 0.f);
                }
                else {

                    selecteionRectangle[0].setPosition(4000.f, 4000.f);
                    selecteionRectangle[1].setPosition(4000.f, 4000.f);
                }
                break;

            case sf::Event::LostFocus:
                if (!paused) {
                    AActors::pauseEntities();
                }
                paused = 1;

                break;

            default:
                break;
            }
        }

        // Updates
        if (!paused) {
            AActors::updateEntities();
        }
        else {
            menu.update();
        }

        // Hntergrundwechsel
        if (backgroundTimer.getElapsedTime() >= sf::seconds(300)) {
            if (Randomizer::randomize(2)) {
                background.setTexture(&backgroundTexture, 0);
            }
            else {
                background.setTexture(&backgroundTexture2, 0);
            }
            backgroundTimer.restart();
        }


        // Render
        Window.clear();

        Window.draw(background);

        for (int i = 0; i < 2; i++) {
            Window.draw(selecteionRectangle[i]);
        }

        AActors::renderEntities();

        geld.render();
        shop.render();

        if (paused) {
            menu.render();
        }

        Window.display();

    }

    Music::stopMusic();

}
