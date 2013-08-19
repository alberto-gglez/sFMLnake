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
