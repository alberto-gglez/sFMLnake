#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "pj.h"
#include "food.h"

class Snake {
public:
    Snake();
    void run();
private:
    sf::RenderWindow window;
    Pj player;
    FoodGenerator foodgen;
    sf::Music music;
};

#endif
