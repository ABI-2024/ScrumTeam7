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

void Level_Endless::start(std::string filename, Progression& progress)
{
    int score = 0;
    sf::Text highscore;
    highscore.setFont(font);
    highscore.setCharacterSize(20);
    highscore.setPosition(1500, 70);

    Music::startMusic();

    shop.setKarten(TowerSelect::openTowerSelect());


    sf::Vector2f pos;
    std::vector<Entity*>* temp = nullptr;

    GameWindow::updateDeltaTime();

    while (Window.isOpen() && active) {

        GameWindow::updateDeltaTime();

        // GameOver
        temp = AActors::getEnemies();
        for (int i = 0; i < temp->size(); i++) {
            if ((*temp)[i]->getPosition().x <= 300.f) {
                this->endLevel(false);
                if (!active) {
                    Music::stopMusic();
                    return;
                }
            }
        }

        // Wellen und Geld
        iWellen.update(geld);
        geld.addKontostand(AActors::getCollectedRevenue());

        score += AActors::getCollectedRevenue() * 10;
        highscore.setString( std::to_string(score) );
        highscore.setOrigin(highscore.getGlobalBounds().width, highscore.getGlobalBounds().height/2);

        AActors::setCollectedRevenue(0);

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
        Window.draw(highscore);

        if (paused) {
            menu.render();
        }

        Window.display();

    }
    progress.addScore( new Highscores{ score });

    Music::stopMusic();


    active = true;
    for (int i = 0; i < progress.highscores.size(); i++) {
        if (progress.highscores[i]->score > score) {
            score = progress.highscores[i]->score;
        }
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Highscore");
    text.setCharacterSize(100);
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(GameWindow::getMainView().getSize().x / 2.f , GameWindow::getMainView().getSize().y/ 2.f -200);
    text.setFillColor(sf::Color::Cyan);


    highscore.setString( std::to_string(score));
    highscore.setCharacterSize(150);
    highscore.setOrigin(highscore.getGlobalBounds().width/2, highscore.getGlobalBounds().height/2);
    highscore.setPosition(GameWindow::getMainView().getSize() / 2.f);
    highscore.setFillColor(sf::Color::Cyan);

    while (Window.isOpen() && active) {

        while (Window.pollEvent(GameEvent)) {
            switch (GameEvent.type)
            {
            case sf::Event::Closed:
                GameWindow::getWindow().close();
                break;
            case sf::Event::MouseButtonPressed:
            case sf::Event::KeyPressed:
                active = false;
                break;
            default:
                break;
            }
        }

        Window.clear();

        Window.draw(highscore);
        Window.draw(text);

        Window.display();
        

    }
}
