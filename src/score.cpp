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

#include "score.h"

#include <sstream>

Score::Score()
    : points(0u)
{
    font.loadFromFile("fonts/alphabeta.ttf");
    text.setFont(font);
    text.setColor(sf::Color::Black);
    text.setPosition(20.f, 10.f);
}

const sf::Text& Score::getText() {
    static std::stringstream ss;
    ss.str(""); ss << points;

    text.setString(ss.str());
    return text;
}
