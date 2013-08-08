#include "highScoreScreen.h"

HighScoreScreen::HighScoreScreen(sf::RenderWindow& window)
    : Screen(window)
{
    font.loadFromFile("font/alphbeta.ttf");
    scores.setFont(font);
}

int HighScoreScreen::run() {
    // show scores

    // wait for any key
    while(window.isOpen()) {
        sf::Event event;
        while(window.waitEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                return 0;
        }
    }
}
