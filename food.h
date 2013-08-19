#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include "pj.h"

class Food : public sf::Sprite {
public:
    Food(const Pj& pj);
    void eat();
    void move();
private:
    sf::SoundBuffer soundBuffer;
    sf::Sound biteSound;
    sf::Texture texture;
    const Pj& pj;
};

#endif
