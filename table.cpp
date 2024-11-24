#include "table.h"
#include <iostream>
#include "turnCard.h"

const float M_PI = 3.14;
void TableWindow::showMenu(GameState& currentState) {
    sf::RenderWindow menuWindow(sf::VideoMode::getDesktopMode(), "Menu");

    sf::Font font;
    if (!font.loadFromFile("Pangolin-Regular.ttf")) {
        std::cout << "Failed to load font" << std::endl;
        currentState = EXIT;
        return;
    }


    sf::Texture texture;
    if (!texture.loadFromFile("background.jpg")) {
        std::cerr << "Failed to load background.jpg" << std::endl;
        currentState = EXIT;
        return;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(
        menuWindow.getSize().x / sprite.getGlobalBounds().width,
        menuWindow.getSize().y / sprite.getGlobalBounds().height
    );

    sf::Text playWithHuman("VS Player", font, 80);
    playWithHuman.setPosition(600, 200);
    playWithHuman.setFillColor(sf::Color::White);

    sf::Text playWithBot("VS Bot", font, 80);
    playWithBot.setPosition(600, 300);
    playWithBot.setFillColor(sf::Color::White);


    turnCard TurnCards;
    TurnCards.run();
    while (menuWindow.isOpen()) {
        sf::Event event;
        while (menuWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                currentState = EXIT;
                menuWindow.close();
            }


            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = menuWindow.mapPixelToCoords(sf::Mouse::getPosition(menuWindow));
                if (playWithHuman.getGlobalBounds().contains(mousePos)) {
                    currentState = GAME_VS_PLAYER;
                    menuWindow.close();
                }
                else if (playWithBot.getGlobalBounds().contains(mousePos)) {
                    currentState = GAME_VS_BOT;
                    menuWindow.close();
                }



                menuWindow.clear();
                menuWindow.draw(sprite);
                menuWindow.draw(playWithHuman);
                menuWindow.draw(playWithBot);
                //-----

                //-----
                menuWindow.display();
            }
        }
    }
}


void TableWindow::showGameTable(bool playWithHuman) {
    sf::RenderWindow gameWindow(sf::VideoMode::getDesktopMode(), playWithHuman ? "VS Player" : "VS Bot");

    turnCard TurnCards;
    sf::Texture texture;
    if (!texture.loadFromFile("table.jpg")) {
        std::cerr << "Failed to load" << std::endl;
        return;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(
        gameWindow.getSize().x / sprite.getGlobalBounds().width,
        gameWindow.getSize().y / sprite.getGlobalBounds().height
    );


    sf::Font font;
    if (!font.loadFromFile("Pangolin-Regular.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    TurnCards.run();
    while (gameWindow.isOpen()) {
        sf::Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }
        }

            gameWindow.clear();
            gameWindow.draw(sprite);
            sf::Text mode(playWithHuman ? "Mode: VS Player" : "Mode: VS Bot", font, 30);
            mode.setPosition(10, 10);
            mode.setFillColor(sf::Color::White);
            gameWindow.draw(mode);


        
            // ------------LOGIC GAME------------//
            if (playWithHuman) {
                // Logic VS Player
            }
            else {
                // Logic VS Bot
            }
            //-----------------------------------//

            gameWindow.display();
        }
    }



