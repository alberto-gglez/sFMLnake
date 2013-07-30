#include "food.h"

#include "globals.h"

Food::Food()
    : _eaten(false)
{
    soundBuffer.loadFromFile("sound/chomp.ogg");
    biteSound.setBuffer(soundBuffer);
    texture.loadFromFile("sprite/apple.png");
    setTexture(texture);
}

void Food::eat() {
    _eaten = true;
    //biteSound.play();
}

void FoodManager::moveFood(Food& food) const {
    bool ok;
    food.refresh();

    // this must be optimized
    do {
        food.setPosition(BPIECE * (std::rand() % int(WIDTH / BPIECE)), BPIECE * (std::rand() % int(HEIGHT / BPIECE)));
        ok = true;

        for(auto i: player->getBody())
            if(i->getPosition() == food.getPosition())
                ok = false;
    } while(!ok);
}
