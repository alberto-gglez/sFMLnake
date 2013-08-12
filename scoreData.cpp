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
        int aux;

        for(int i = 0; i < 10; ++i) {
            is.read((char*)&aux, sizeof(int));
            score.push_back(aux);
        }

        is.close();
    } else {
        for(int i = 0; i < 10; ++i)
            score.push_back(0);

        save();
    }
}

void ScoreData::save() {
    ofstream os("score.dat", ios::binary | ios::out);

    if(os) {
        for(unsigned int i = 0; i < 10 && i < score.size(); ++i)
            os.write((char*)&score[i], sizeof(int));

        os.close();
    }
}

void ScoreData::addScore(int points) {
    score.push_back(points);

    std::sort(score.begin(), score.end(), [](int x, int y){ return x > y; });
}
