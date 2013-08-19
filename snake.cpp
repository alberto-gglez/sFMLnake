#include "snake.h"

Snake::Snake()
    : window(sf::VideoMode(WIDTH, HEIGHT), "sFMLnake"),
      menuScreen(window),
      highScoreScreen(window, scoreData),
      gameScreen(window, scoreData)
{
    window.setFramerateLimit(60u);
    std::srand(std::time(nullptr));
}

void Snake::run() {
    while(window.isOpen()) {
        switch(menuScreen.run()) {
            case 0: gameScreen.run(); break;
            case 1: highScoreScreen.run(); break;
            case 2: window.close(); break;
        }
    }
}
