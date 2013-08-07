/*
    Snake clone made with SFML 2
    by Alberto García

    ToDo:
        - Death
        - Victory condition
*/

#include "snake.h"

Snake::Snake()
    : window(sf::VideoMode(WIDTH, HEIGHT), "sFMLnake"), menuScreen(window), gameScreen(window)
{
    window.setFramerateLimit(60u);
    std::srand(std::time(nullptr));
}

void Snake::run() {
    while(window.isOpen()) {
        menuScreen.run();
        gameScreen.run();
    }
}
