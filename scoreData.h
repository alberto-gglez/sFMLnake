#ifndef SCOREDATA_H
#define SCOREDATA_H

#include <vector>

class ScoreData {
public:
    ScoreData();
    const std::vector<int>& getHighScore() const;
    void save();
    void addScore(int points);
private:
    std::vector<int> score;
};

inline const std::vector<int>& ScoreData::getHighScore() const {
    return score;
}

#endif
