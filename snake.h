#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "pj.h"

class Snake {
public:
    Snake();
    void run();
private:
    sf::RenderWindow window;
    Pj player;
};

#endif
