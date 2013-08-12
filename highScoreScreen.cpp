#include "highScoreScreen.h"

#include "scoreData.h"
#include <sstream>
#include <vector>

HighScoreScreen::HighScoreScreen(sf::RenderWindow& window, ScoreData& scoreData)
    : Screen(window), scoreData(scoreData)
{
    font.loadFromFile("font/alphbeta.ttf");
    scoreTxt.setFont(font);
    scoreTxt.setColor(sf::Color::Black);

    name.setFont(font);
    name.setString("High scores");
    name.setColor(sf::Color::Black);
    name.scale(2.5f, 2.5f);
    name.setPosition(120.f, 40.f);
}

int HighScoreScreen::run() {
    std::stringstream ss;

    // show scores
    unsigned int scoreDataSize = scoreData.getHighScore().size();

    // wait for any key
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return 0;
        }

        // output
        window.clear(sf::Color::Green);

        window.draw(name);
        for(unsigned int i = 0; i < 10 && i < scoreDataSize; ++i) {
            scoreTxt.setPosition(175.f, 150.f + (30 * i));
            ss << "#" << (i+1) << "\t\t\t" << scoreData.getHighScore().at(i);
            scoreTxt.setString(ss.str());
            ss.str("");

            window.draw(scoreTxt);
        }

        window.display();
    }

    return -1;
}
