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

#ifndef GAME_SCR_H
#define GAME_SCR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "pj.h"
#include "food.h"
#include "score.h"
#include "screen.h"

class ScoreData;

class GameScreen : public Screen {
public:
    GameScreen(sf::RenderWindow& window, ScoreData& scoreData);
    int run();
    int gameOver();
private:
    Pj player;
    sf::Music music;
    sf::SoundBuffer backSndBuff;
    sf::Sound backSnd;
    Score score;
    ScoreData& scoreData;
};

#endif
