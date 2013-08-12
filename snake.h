#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "scoreData.h"
#include "gameScreen.h"
#include "menuScreen.h"
#include "highScoreScreen.h"

class Snake {
public:
    Snake();
    void run();
private:
    sf::RenderWindow window;
    MenuScreen menuScreen;
    HighScoreScreen highScoreScreen;
    GameScreen gameScreen;
    ScoreData scoreData;
};

#endif
