#include "pj.h"

Pj::Pj(int x, int y)
    : direction(RIGHT)
{
    body.push_front(BodyPiece(x, y));
    body.push_front(BodyPiece(x + 20, y));
    body.push_front(BodyPiece(x + 40, y));
}

void Pj::update() {
    switch(direction) {
        case UP:    moveUp();    break;
        case RIGHT: moveRight(); break;
        case LEFT:  moveLeft();  break;
        case DOWN:  moveDown();  break;
    }
}

void Pj::moveUp() {
    BodyPiece head = body.front();

    head.coords().y -= 20;
    if(head.coords().y < 0)
        head.coords().y = 460;

    body.push_front(head);
    body.pop_back();
}

void Pj::moveRight() {
    BodyPiece head = body.front();

    head.coords().x += 20;
    if(head.coords().x > 620)
        head.coords().x = 0;

    body.push_front(head);
    body.pop_back();
}

void Pj::moveLeft() {
    BodyPiece head = body.front();

    head.coords().x -= 20;
    if(head.coords().x < 0)
        head.coords().x = 620;

    body.push_front(head);
    body.pop_back();
}

void Pj::moveDown() {
    BodyPiece head = body.front();

    head.coords().y += 20;
    if(head.coords().y > 460)
        head.coords().y = 0;

    body.push_front(head);
    body.pop_back();
}

void Pj::draw(sf::RenderWindow& window) const {
    sf::RectangleShape piece;
    piece.setSize(sf::Vector2f(20.f, 20.f));
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
