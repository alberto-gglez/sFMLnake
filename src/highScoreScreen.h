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

#ifndef HIGHSCORE_SRC_H
#define HIGHSCORE_SRC_H

#include "screen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ScoreData;

class HighScoreScreen : public Screen {
public:
    HighScoreScreen(sf::RenderWindow& window, ScoreData& scoreData);
    int run();
private:
    sf::Font font;
    sf::Text scoreTxt, nameTxt, backTxt;
    sf::SoundBuffer sndBuffer;
    sf::Sound backSnd;
    ScoreData& scoreData;
};

#endif
