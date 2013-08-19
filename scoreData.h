#ifndef SCOREDATA_H
#define SCOREDATA_H

#include <vector>

class ScoreData {
public:
    ScoreData();
    const std::vector<unsigned int>& getHighScore() const;
    void save();
    void addScore(unsigned int points);
private:
    std::vector<unsigned int> score;
};

inline const std::vector<unsigned int>& ScoreData::getHighScore() const {
    return score;
}

#endif
