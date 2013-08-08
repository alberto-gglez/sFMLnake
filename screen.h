#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

class Screen {
public:
    Screen(sf::RenderWindow& window);
    virtual int run() = 0;
    virtual ~Screen() = default;
protected:
    sf::RenderWindow& window;
};

inline Screen::Screen(sf::RenderWindow& window) : window(window) {}

#endif
