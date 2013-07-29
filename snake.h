#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "pj.h"
#include "food.h"
#include "score.h"

class Snake {
public:
    Snake();
    void run();
    bool checkVictory() const;
    void win();
    void lose();
private:
    sf::RenderWindow window;
    Pj player;
    FoodManager foodMan;
    sf::Music music;
    Score score;
};

inline bool Snake::checkVictory() const {
    return player.getBody().size() == MAXBPIECES;
}

#endif
