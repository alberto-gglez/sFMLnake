#ifndef FOOD_H
#define FOOD_H

#include <SFML/Audio.hpp>
#include <cstdlib>
#include "pj.h"

class Food {
public:
    Food(int x = 0, int y = 0);
    void eat();
    void refresh();
    bool eaten() const;

    const sf::Vector2i& coords() const;
    sf::Vector2i& coords();
    void draw(sf::RenderWindow& window) const;
private:
    sf::Vector2i _coords;
    bool _eaten;
    sf::SoundBuffer soundBuffer;
    sf::Sound biteSound;
};

inline void Food::refresh() { _eaten = false; }
inline bool Food::eaten() const { return _eaten; }
inline const sf::Vector2i& Food::coords() const { return _coords; }
inline       sf::Vector2i& Food::coords()       { return _coords; }

class FoodGenerator {
public:
    FoodGenerator(const Pj& pj);
    void moveFood(Food& food) const;
private:
    const Pj* player;
};

inline FoodGenerator::FoodGenerator(const Pj& pj) : player(&pj) {}

#endif
