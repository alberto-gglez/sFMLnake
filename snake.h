#ifndef SNAKE_H
#define SNAKE_H

#include "gameScreen.h"
#include "menuScreen.h"
#include "highScoreScreen.h"
#include <SFML/Graphics.hpp>

class Snake {
public:
    Snake();
    void run();
private:
    sf::RenderWindow window;
    MenuScreen menuScreen;
    HighScoreScreen highScoreScreen;
    GameScreen gameScreen;
};

#endif
