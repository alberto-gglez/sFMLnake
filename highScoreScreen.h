#ifndef HIGHSCORE_SRC_H
#define HIGHSCORE_SRC_H

#include "screen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class HighScoreScreen : public Screen {
public:
    HighScoreScreen(sf::RenderWindow& window);
    int run();
private:
    sf::Font font;
    sf::Text scores;
    sf::SoundBuffer sndBuffer;
    sf::Sound backSnd;
};

#endif
