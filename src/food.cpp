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

#include "food.h"

#include "globals.h"

Food::Food(const Pj& pj)
    : pj(pj)
{
    soundBuffer.loadFromFile("sounds/chomp.ogg");
    biteSound.setBuffer(soundBuffer);
    texture.loadFromFile("sprites/apple.png");
    setTexture(texture);
    setOrigin(BPIECE / 2.f, BPIECE / 2.f);
}

void Food::eat() {
    biteSound.play();
    move();
}

void Food::move() {
    bool marks[MAXBPIECES] = { false };

    unsigned int nSpaces = MAXBPIECES - pj.getBody().size(),
                 freeSpaces[nSpaces];

    for(auto i: pj.getBody())
        marks[coordsToInt(i->getPosition())] = true;

    unsigned int j = 0;
    for(unsigned int i = 0; i < MAXBPIECES && j < nSpaces; ++i)
        if(!marks[i])
            freeSpaces[j++] = i;

    int aux = int(std::rand() % nSpaces);
    sf::Vector2f aux2f = intToCoords(freeSpaces[aux]);
    setPosition(aux2f);
}
