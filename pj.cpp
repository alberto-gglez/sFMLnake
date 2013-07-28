#include "pj.h"
#include "food.h"

Pj::Pj(int x, int y)
    : direction(RIGHT)
{
    body.push_front(BodyPiece(x, y));
    body.push_front(BodyPiece(x + BPIECE, y));
    body.push_front(BodyPiece(x + 2 * BPIECE, y));
}

void Pj::readInput(const sf::Event& event) {
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Up)
            setDirection(UP);
        if(event.key.code == sf::Keyboard::Right)
            setDirection(RIGHT);
        if(event.key.code == sf::Keyboard::Left)
            setDirection(LEFT);
        if(event.key.code == sf::Keyboard::Down)
            setDirection(DOWN);
        // for testing
        if(event.key.code == sf::Keyboard::Space)
            grow();
    }
}

void Pj::update(Food& food) {
    switch(direction) {
        case UP:    moveUp();    break;
        case RIGHT: moveRight(); break;
        case LEFT:  moveLeft();  break;
        case DOWN:  moveDown();  break;
    }

    if(body.front().coords() == food.coords()) {
        food.eat();
        grow();
    }
}

void Pj::moveUp() {
    BodyPiece head = body.front();

    head.coords().y -= BPIECE;
    if(head.coords().y < 0)
        head.coords().y = HEIGHT - BPIECE;

    body.push_front(head);
    body.pop_back();
}

void Pj::moveRight() {
    BodyPiece head = body.front();

    head.coords().x += BPIECE;
    if(head.coords().x > WIDTH - BPIECE)
        head.coords().x = 0;

    body.push_front(head);
    body.pop_back();
}

void Pj::moveLeft() {
    BodyPiece head = body.front();

    head.coords().x -= BPIECE;
    if(head.coords().x < 0)
        head.coords().x = WIDTH - BPIECE;

    body.push_front(head);
    body.pop_back();
}

void Pj::moveDown() {
    BodyPiece head = body.front();

    head.coords().y += BPIECE;
    if(head.coords().y > HEIGHT - BPIECE)
        head.coords().y = 0;

    body.push_front(head);
    body.pop_back();
}

void Pj::draw(sf::RenderWindow& window) const {
    sf::RectangleShape piece;
    piece.setSize(sf::Vector2f(BPIECE, BPIECE));
    piece.setFillColor(sf::Color::White);

    for(auto& i: body) {
        piece.setPosition(i.coords().x, i.coords().y);
        window.draw(piece);
    }
}

void Pj::grow() {
    BodyPiece p = body.back();
    body.push_back(BodyPiece(p.coords().x, p.coords().y));
}
