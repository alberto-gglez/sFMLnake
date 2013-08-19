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
