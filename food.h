#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include "pj.h"

class Food : public sf::Sprite {
public:
    Food();
    void eat();
    void refresh();
    bool eaten() const;
private:
    bool _eaten;
    sf::SoundBuffer soundBuffer;
    sf::Sound biteSound;
    sf::Texture texture;
};

inline void Food::refresh() { _eaten = false; }
inline bool Food::eaten() const { return _eaten; }

class FoodManager {
public:
    FoodManager(const Pj& pj);
    void moveFood(Food& food) const;
private:
    const Pj* player;
};

inline FoodManager::FoodManager(const Pj& pj) : player(&pj) {}

#endif
