#ifndef GAME_SCR_H
#define GAME_SCR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "pj.h"
#include "food.h"
#include "score.h"
#include "screen.h"

class GameScreen : public Screen {
public:
    GameScreen(sf::RenderWindow& window);
    int run();
private:
    Pj player;
    FoodManager foodMan;
    sf::Music music;
    Score score;
};

#endif
