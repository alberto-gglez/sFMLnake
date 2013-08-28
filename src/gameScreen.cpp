/*
    sFMLnake: A simple Snake clone made with SFML 2.
    Copyright (C) 2013  Alberto García González

    This file is part of sFMLnake.

    sFMLnake is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sFMLnake is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with sFMLnake.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "gameScreen.h"

#include "globals.h"
#include <ctime>
#include <cstdlib>
#include "scoreData.h"
#include <sstream>

GameScreen::GameScreen(sf::RenderWindow& window, ScoreData& scoreData)
    : Screen(window), scoreData(scoreData)
{
    music.openFromFile("sounds/music.ogg");

    backSndBuff.loadFromFile("sounds/backSnd.ogg");
    backSnd.setBuffer(backSndBuff);
}

int GameScreen::run() {
    sf::Clock clock;
    Food food(player);
    food.move();

    music.setLoop(true);
    music.setVolume(50.f);
    music.play();

    while(window.isOpen()) {
        sf::Time t = clock.getElapsedTime();
        sf::Event event;

        // input
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            player.readInput(event);
        }

        // logic
        if(t.asSeconds() >= 0.44f) {
            // checks for collisions
            if(!player.update(food, score)) {
                scoreData.addScore(score.getPoints());
                scoreData.save();
                music.stop();

                gameOver();

                score.reset();
                player.reset();

                return 0;
            }
            clock.restart();
        }

        // output
        window.clear(sf::Color(0x9f, 0x6d, 0x47));

        player.draw(window);
        window.draw(food);
        window.draw(score.getText());

        window.display();
    }

    return 0;
}

int GameScreen::gameOver() {
    std::stringstream ss;

    sf::Font font;
    font.loadFromFile("fonts/alphabeta.ttf");
    sf::Text gameOverTxt;
    gameOverTxt.setFont(font);

    sf::RectangleShape rectShape(sf::Vector2f(500.f, 180.f));
    rectShape.setOrigin(250.f, 90.f);
    rectShape.setPosition(WIDTH / 2, HEIGHT / 2);
    rectShape.setFillColor(sf::Color(0xCA, 0x92, 0x6C));
    rectShape.setOutlineThickness(3.f);
    rectShape.setOutlineColor(sf::Color::Black);
    window.draw(rectShape);

    gameOverTxt.setString("You are dead");
    gameOverTxt.setPosition(WIDTH / 2 - gameOverTxt.getLocalBounds().width / 2, 160.f);
    gameOverTxt.setColor(sf::Color::Black);
    window.draw(gameOverTxt);

    ss << "Your score: " << score.getPoints();
    gameOverTxt.setString(ss.str());
    gameOverTxt.setPosition(WIDTH / 2 - gameOverTxt.getLocalBounds().width / 2, 190.f);
    window.draw(gameOverTxt);

    if(score.getPoints() > scoreData.getHighScore().back())
        gameOverTxt.setString("New record!");
    else
        gameOverTxt.setString("Try again!");
    gameOverTxt.setPosition(WIDTH / 2 - gameOverTxt.getLocalBounds().width / 2, 220.f);
    window.draw(gameOverTxt);

    gameOverTxt.setString("Back to main menu");
    gameOverTxt.setColor(sf::Color::White);
    gameOverTxt.setPosition(WIDTH / 2 - gameOverTxt.getLocalBounds().width / 2, 280.f);
    window.draw(gameOverTxt);

    window.display();

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                backSnd.play();
                return 0;
            }
        }
    }

    return -1;
}
