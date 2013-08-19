#include "food.h"

#include "globals.h"

Food::Food(const Pj& pj)
    : pj(pj)
{
    soundBuffer.loadFromFile("sounds/chomp.ogg");
    biteSound.setBuffer(soundBuffer);
    texture.loadFromFile("sprites/apple.png");
    setTexture(texture);
    setOrigin(BPIECE / 2.f, BPIECE / 2.f);
}

void Food::eat() {
    biteSound.play();
    move();
}

void Food::move() {
    bool ok;

    // this would be optimized
    do {
        setPosition(BPIECE * (std::rand() % int(WIDTH / BPIECE)) + 20.f, BPIECE * (std::rand() % int(HEIGHT / BPIECE)) + 20.f);
        ok = true;

        for(auto i: pj.getBody())
            if(i->getPosition() == getPosition())
                ok = false;
    } while(!ok);
}
