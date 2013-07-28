#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include "globals.h"

class Score {
public:
    Score();
    void addPoint();
    unsigned int getPoints() const;
    const sf::Text& getText();
private:
    unsigned int points;
    sf::Font font;
    sf::Text text;
};

inline void Score::addPoint() { ++points; }
inline unsigned int Score::getPoints() const { return points; }

#endif
