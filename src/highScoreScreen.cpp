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

#include "highScoreScreen.h"

#include "scoreData.h"
#include <sstream>
#include <vector>

HighScoreScreen::HighScoreScreen(sf::RenderWindow& window, ScoreData& scoreData)
    : Screen(window), scoreData(scoreData)
{
    font.loadFromFile("fonts/alphabeta.ttf");
    scoreTxt.setFont(font);
    scoreTxt.setColor(sf::Color::Black);

    nameTxt.setFont(font);
    nameTxt.setString("High scores");
    nameTxt.setColor(sf::Color::Black);
    nameTxt.scale(2.5f, 2.5f);
    nameTxt.setPosition(120.f, 10.f);

    backTxt.setFont(font);
    backTxt.setString("Back");
    backTxt.setColor(sf::Color::White);
    backTxt.setPosition(280.f, 420.f);

    sndBuffer.loadFromFile("sounds/backSnd.ogg");
    backSnd.setBuffer(sndBuffer);
}

int HighScoreScreen::run() {
    std::stringstream ss;

    // show scores
    unsigned int scoreDataSize = scoreData.getHighScore().size();

    // I draw the scores only once
    window.clear(sf::Color(0x9f, 0x6d, 0x47));
    window.draw(nameTxt);
    for(unsigned int i = 0; i < 10 && i < scoreDataSize; ++i) {
        // score number
        ss.str("");
        ss << "#" << (i+1);
        scoreTxt.setString(ss.str());
        scoreTxt.setPosition(175.f, 110.f + (30 * i));
        window.draw(scoreTxt);
        // score
        ss.str("");
        ss << scoreData.getHighScore().at(i);
        scoreTxt.setString(ss.str());
        scoreTxt.setPosition(470.f - scoreTxt.getLocalBounds().width, 110.f + (30 * i));
        window.draw(scoreTxt);
    }
    window.draw(backTxt);
    window.display();

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                backSnd.play();
                return 0;
            }
        }
    }

    return -1;
}
