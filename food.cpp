#include "food.h"

#include "globals.h"

Food::Food()
    : _eaten(false)
{
    soundBuffer.loadFromFile("sound/chomp.ogg");
    biteSound.setBuffer(soundBuffer);
    texture.loadFromFile("sprite/apple.png");
    setTexture(texture);
    setOrigin(BPIECE / 2.f, BPIECE / 2.f);
}

void Food::eat() {
    _eaten = true;
    biteSound.play();
}

void FoodManager::moveFood(Food& food) const {
    bool ok;
    food.refresh();

    // this must be optimized
    do {
        food.setPosition(BPIECE * (std::rand() % int(WIDTH / BPIECE)) + 20.f, BPIECE * (std::rand() % int(HEIGHT / BPIECE)) + 20.f);
        ok = true;

        for(auto i: player->getBody())
            if(i->getPosition() == food.getPosition())
                ok = false;
    } while(!ok);
}
