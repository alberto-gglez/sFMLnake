#ifndef SCORE_H
#define SCORE_H

#include "globals.h"
#include <SFML/Graphics.hpp>

class Score {
public:
    Score();
    void addPoints(unsigned int n = 1);
    unsigned int getPoints() const;
    const sf::Text& getText();
    void reset();
private:
    unsigned int points;
    sf::Font font;
    sf::Text text;
};

inline void Score::addPoints(unsigned int n) { points += n; }
inline unsigned int Score::getPoints() const { return points; }
inline void Score::reset() { points = 0; }

#endif
