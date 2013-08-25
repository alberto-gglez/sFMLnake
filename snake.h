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

#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "scoreData.h"
#include "gameScreen.h"
#include "menuScreen.h"
#include "highScoreScreen.h"

class Snake {
public:
    Snake();
    void run();
private:
    sf::RenderWindow window;
    MenuScreen menuScreen;
    HighScoreScreen highScoreScreen;
    GameScreen gameScreen;
    ScoreData scoreData;
};

#endif
