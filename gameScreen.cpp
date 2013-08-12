#include "gameScreen.h"

#include "globals.h"
#include <ctime>
#include <cstdlib>
#include "scoreData.h"

#include <iostream>

GameScreen::GameScreen(sf::RenderWindow& window, ScoreData& scoreData)
    : Screen(window), foodMan(player), scoreData(scoreData)
{
    music.openFromFile("sound/music.ogg");
}

int GameScreen::run() {
    sf::Clock clock;
    Food food;
    foodMan.moveFood(food);

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
            if(!player.update(food, score)) {
                scoreData.addScore(score.getPoints());
                scoreData.save();
                return -1;
            }
            clock.restart();
        }

        if(food.eaten())
            foodMan.moveFood(food);

        // output
        window.clear(sf::Color::Green);

        player.draw(window);
        window.draw(food);
        window.draw(score.getText());

        window.display();
    }

    return 0;
}

