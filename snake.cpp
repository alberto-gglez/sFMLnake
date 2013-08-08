/*
    Snake clone made with SFML 2
    by Alberto García

    ToDo:
        - Death
        - Victory condition
*/

#include "snake.h"

Snake::Snake()
    : window(sf::VideoMode(WIDTH, HEIGHT), "sFMLnake"), menuScreen(window), highScoreScreen(window), gameScreen(window)
{
    window.setFramerateLimit(60u);
    std::srand(std::time(nullptr));
}

void Snake::run() {
    while(window.isOpen()) {
        switch(menuScreen.run()) {
            case 0: gameScreen.run(); break;
            case 1: highScoreScreen.run(); break;
            default: window.close();
        }
    }
}
