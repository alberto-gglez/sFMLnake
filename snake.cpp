#include "snake.h"

/*
    Snake clone made with SFML 2
    by Alberto García

    ToDo:
        - Sound and music
        - Collisions
        - Snake "food"?
        - Score
*/

Snake::Snake()
    : window(sf::VideoMode(640, 480), "sFMLnake"), player(20, 20)
{
    window.setFramerateLimit(60u);
}

void Snake::run() {
    sf::Clock clock;

    while(window.isOpen()) {
        sf::Time t = clock.getElapsedTime();
        sf::Event event;

        // input
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Up)
                    player.setDirection(Pj::Direction::UP);
                if(event.key.code == sf::Keyboard::Right)
                    player.setDirection(Pj::Direction::RIGHT);
                if(event.key.code == sf::Keyboard::Left)
                    player.setDirection(Pj::Direction::LEFT);
                if(event.key.code == sf::Keyboard::Down)
                    player.setDirection(Pj::Direction::DOWN);
               // for testing
                if(event.key.code == sf::Keyboard::Space)
                    player.grow();
            }
        }

        // logic
        if(t.asSeconds() >= 0.4f) {
            player.update();
            clock.restart();
        }

        // output
        window.clear(sf::Color::Green);

        player.draw(window);

        window.display();
    }
}
