#ifndef MENU_SCR_H
#define MENU_SCR_H

#include "screen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuScreen : public Screen {
public:
    MenuScreen(sf::RenderWindow& window);
    int run();
private:
    sf::Font font;
    sf::Text name, gameStartTxt, scoresTxt, exitTxt;

    sf::SoundBuffer selectBuff, confirmBuff, backBuff;
    sf::Sound selectSnd, confirmSnd, backSnd;

    int option;
};

#endif
