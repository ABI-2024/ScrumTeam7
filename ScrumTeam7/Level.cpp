#include "Level.h"

#include "Window.h"
#include "Menu_Options.h"

#include "Music.h"

sf::Vector2f Level::TileSelection()
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

void Level::buttonEvents()
{
    switch (this->menu.mouseClick()) {
    case 0:
        // Spiel geht weiter
        paused = false;
        AActors::continueEntities();
        break;
    case 1:
        // Optionsmenu wird geoeffnet
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

void Level::endLevel(bool isVictory)
{
    while (Window.isOpen() && active)
    {
        // Events
        while (Window.pollEvent(GameEvent)) {
            switch (GameEvent.type)
            {

            case sf::Event::Closed:
                GameWindow::getWindow().close();
                break;

            case sf::Event::KeyPressed:
                active = false;
                break;

            case sf::Event::MouseButtonPressed:
                active = false;
                break;

            default:
                break;
            }
        }

        Window.clear();

        Window.draw(endOfTheLevel);

        if (isVictory) {
            Window.draw(victory);
        }
        else {
            Window.draw(gameOver);
        }

        Window.display();
    }
}

Level::Level()
    : active(true), paused(false), shop(&geld)

{
    endOfTheLevel.setPosition(GameWindow::getMainView().getSize() / 2.f);
    endOfTheLevel.setSize({ GameWindow::getMainView().getSize().x, GameWindow::getMainView().getSize().y - 100.f });
    endOfTheLevel.setOrigin(endOfTheLevel.getSize() / 2.f);
    endOfTheLevel.setFillColor(sf::Color(127, 127, 127, 63));

    font.loadFromFile("resource/fonts/Broken Console Bold.otf");

    gameOver.setFont(font);
    gameOver.setString("GAME OVER");
    gameOver.setFillColor(sf::Color::Red);
    gameOver.setCharacterSize(200.f);
    gameOver.setOrigin(gameOver.getGlobalBounds().width/2.f, gameOver.getGlobalBounds().height / 2.f);
    gameOver.setPosition(GameWindow::getMainView().getSize()/2.f);

    victory.setFont(font);
    victory.setString("VICTORY");
    victory.setFillColor(sf::Color::Yellow);
    victory.setCharacterSize(200.f);
    victory.setOrigin(victory.getGlobalBounds().width / 2.f, victory.getGlobalBounds().height / 2.f);
    victory.setPosition(GameWindow::getMainView().getSize()/2.f);


    background.setSize(GameWindow::getMainView().getSize());
    background.setPosition(0.f, 0.f);


    selecteionRectangle[0].setSize({ GameWindow::getMainView().getSize().x, 150.f });
    selecteionRectangle[0].setOrigin(0.f, selecteionRectangle[0].getSize().y / 2.f);
    selecteionRectangle[1].setSize({ 150.f, GameWindow::getMainView().getSize().y });
    selecteionRectangle[1].setOrigin(selecteionRectangle[1].getSize().x / 2.f, 0.f);
    for (int i = 0; i < 2; i++) {
        selecteionRectangle[i].setPosition(4000.f, 4000.f);
        selecteionRectangle[i].setFillColor(sf::Color(127, 127, 127, 64));
    }
}

Level::~Level()
{
}

void Level::start(std::string filename , Progression& progress)
{

    Music::startMusic();

    shop.setKarten(TowerSelect::openTowerSelect());


    sf::Vector2f pos;
    std::vector<Entity*>* temp = nullptr;

    welle.setFilename(filename);
    welle.WellenDaten();
    welle.SortListeSchueler();

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
        welle.Wellenfunktion(geld);
        geld.addKontostand(AActors::getCollectedRevenue());
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
