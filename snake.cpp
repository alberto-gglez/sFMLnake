/*
    Snake clone made with SFML 2
    by Alberto García

    ToDo:
        - Death
        - Victory condition
*/

#include "globals.h"
#include "snake.h"
#include <ctime>
#include <cstdlib>

#include <iostream>

Snake::Snake()
    : window(sf::VideoMode(WIDTH, HEIGHT), "sFMLnake"), foodMan(player)
{
    window.setFramerateLimit(60u);
    std::srand(std::time(nullptr));
    music.openFromFile("sound/music.ogg");
}

void Snake::run() {
    sf::Clock clock;
    Food food;
    foodMan.moveFood(food);

    music.setLoop(true);
    music.setVolume(50.f);
    //music.play();

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
            if(!player.update(food, score))
                lose();
            clock.restart();
        }

        if(food.eaten())
            foodMan.moveFood(food);

        if(checkVictory())
            win();

        // output
        window.clear(sf::Color::Green);

        player.draw(window);
        food.draw(window);
        window.draw(score.getText());

        window.display();
    }
}

void Snake::win() const {

}

void Snake::lose() {
    window.close();
}
