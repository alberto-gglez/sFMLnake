#include "food.h"

#include "globals.h"

Food::Food(int x, int y)
    : _coords(x, y), _eaten(false)
{
    soundBuffer.loadFromFile("sound/chomp.ogg");
    biteSound.setBuffer(soundBuffer);
}

void Food::eat() {
    _eaten = true;
    biteSound.play();
}

void Food::draw(sf::RenderWindow& window) const {
    if(!_eaten) {
        sf::RectangleShape foodShape;
        foodShape.setSize(sf::Vector2f(BPIECE, BPIECE));
        foodShape.setFillColor(sf::Color::Red);
        foodShape.setPosition(coords().x, coords().y);

        window.draw(foodShape);
    }
}

void FoodGenerator::moveFood(Food& food) const {
    bool ok;
    food.refresh();

    // this must be optimized
    do {
        food.coords().x = BPIECE * (std::rand() % (WIDTH / BPIECE));
        food.coords().y = BPIECE * (std::rand() % (HEIGHT / BPIECE));
        ok = true;

        for(auto& i: player->getBody())
            if(i.coords() == food.coords())
                ok = false;
    } while(!ok);
}
