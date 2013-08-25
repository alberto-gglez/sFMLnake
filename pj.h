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

#ifndef PJ_H
#define PJ_H

#include <SFML/Graphics.hpp>
#include <deque>
#include "globals.h"

class Food;
class Score;

class Pj {
public:
    typedef sf::Sprite BodyPiece;
    typedef std::deque<BodyPiece*> Body;
    enum Direction {UP, RIGHT, LEFT, DOWN};

    Pj();

    void readInput(const sf::Event& event);
    bool update(Food& food, Score& score);
    const Body& getBody() const;
    void draw(sf::RenderWindow& window) const;
    void grow();
    bool checkCollisions(const sf::Vector2f& v) const;
    void reset();

    ~Pj();
private:
    Direction actualDir, nextDir;
    Body body;
    sf::Texture slimTexture, fatTexture;
    bool hasGrown, isFat;
    void destroyBody();

    bool moveUp();
    bool moveRight();
    bool moveLeft();
    bool moveDown();
    Direction prevPiecePos(unsigned int i) const;
};

inline const Pj::Body& Pj::getBody() const { return body; }

#endif
