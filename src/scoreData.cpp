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

#include "scoreData.h"

#include <fstream>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::ios;

ScoreData::ScoreData() {
    ifstream is("score.dat", ios::binary | ios::in);

    if(is) {
        unsigned int aux;

        for(int i = 0; i < 10; ++i) {
            is.read((char*)&aux, sizeof(unsigned int));
            score.push_back(aux);
        }

        is.close();
    } else {
        for(unsigned int i = 0; i < 10; ++i)
            score.push_back(0);

        save();
    }
}

void ScoreData::save() {
    ofstream os("score.dat", ios::binary | ios::out);

    if(os) {
        for(unsigned int i = 0; i < 10 && i < score.size(); ++i)
            os.write((char*)&score[i], sizeof(unsigned int));

        os.close();
    }
}

void ScoreData::addScore(unsigned int points) {
    score.push_back(points);

    std::sort(score.begin(), score.end(), [](unsigned int x, unsigned int y){ return x > y; });
}
