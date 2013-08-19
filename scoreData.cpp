#include "scoreData.h"

#include <fstream>
#include <iostream>
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
