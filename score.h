/*
    sFMLnake: A simple Snake clone made with SFML 2.
    Copyright (C) 2013  Alberto García González

    This file is part of sFMLnake.

    sFMLnake is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sFMLnake is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with sFMLnake.  If not, see <http://www.gnu.org/licenses/>.
*/

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
