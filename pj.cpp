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
    body.pop_back();
    body.push_front(BodyPiece(head.coords().x, head.coords().y - 20));
}

void Pj::moveRight() {
    BodyPiece head = body.front();
    body.pop_back();
    body.push_front(BodyPiece(head.coords().x + 20, head.coords().y));
}

void Pj::moveLeft() {
    BodyPiece head = body.front();
    body.pop_back();
    body.push_front(BodyPiece(head.coords().x - 20, head.coords().y));
}

void Pj::moveDown() {
    BodyPiece head = body.front();
    body.pop_back();
    body.push_front(BodyPiece(head.coords().x, head.coords().y + 20));
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
