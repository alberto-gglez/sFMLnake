/*
    Snake clone made with SFML 2
    by Alberto García

    ToDo:
        - Collisions
        - Score
*/

#include "globals.h"
#include "snake.h"
#include <ctime>
#include <cstdlib>

Snake::Snake()
    : window(sf::VideoMode(WIDTH, HEIGHT), "sFMLnake"), foodgen(player)
{
    window.setFramerateLimit(60u);
    std::srand(std::time(nullptr));
    music.openFromFile("sound/music.ogg");
}

void Snake::run() {
    sf::Clock clock;
    Food food;
    foodgen.moveFood(food);

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
        if(t.asSeconds() >= 0.4f) {
            player.update(food);
            clock.restart();
        }

        if(food.eaten())
            foodgen.moveFood(food);

        // output
        window.clear(sf::Color::Green);

        player.draw(window);
        food.draw(window);

        window.display();
    }
}
