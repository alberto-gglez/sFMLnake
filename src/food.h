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

inline unsigned int coordsToInt(const sf::Vector2f& v) {
    return ((v.x - 20.f) / BPIECE) + ((v.y - 20.f) / 40.f) * 16.f;
}

inline sf::Vector2f intToCoords(unsigned int i) {
    return sf::Vector2f(float(i % 16) * 40.f + 20.f, float(i / 16) * 40.f + 20.f);
}

#endif
