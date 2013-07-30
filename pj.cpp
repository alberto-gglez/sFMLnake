#include "pj.h"
#include "food.h"
#include "score.h"

Pj::Pj(float x, float y)
    : direction(RIGHT)
{
    texture.loadFromFile("sprite/snake.png");

    BodyPiece* b = new BodyPiece;
    b->setTexture(texture);
    b->setOrigin(BPIECE / 2.f, BPIECE / 2.f);
    b->setPosition(x, y);
    body.push_front(b);

    b = new BodyPiece;
    b->setTexture(texture);
    b->setOrigin(BPIECE / 2.f, BPIECE / 2.f);
    b->setPosition(x + BPIECE, y);
    body.push_front(b);

    b = new BodyPiece;
    b->setTexture(texture);
    b->setOrigin(BPIECE / 2.f, BPIECE / 2.f);
    b->setPosition(x + 2 * BPIECE, y);
    body.push_front(b);
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

bool Pj::update(Food& food, Score& score) {
    bool noCollisions;

    switch(direction) {
        case UP:    noCollisions = moveUp();    break;
        case RIGHT: noCollisions = moveRight(); break;
        case LEFT:  noCollisions = moveLeft();  break;
        case DOWN:  noCollisions = moveDown();  break;
    }

    if(body.front()->getPosition() == food.getPosition()) {
        food.eat();
        score.addPoint();
        grow();
    }

    return noCollisions;
}

bool Pj::moveUp() {
    sf::Vector2f pos = body.front()->getPosition();

    pos.y -= BPIECE;
    if(pos.y < 0)
        pos.y = HEIGHT - BPIECE;

    if(!checkCollisions(pos)) {
        BodyPiece* b = body.back();
        b->setPosition(pos);
        body.push_front(b);
        body.pop_back();

        return true;
    }

    return false;
}

bool Pj::moveRight() {
    sf::Vector2f pos = body.front()->getPosition();

    pos.x += BPIECE;
    if(pos.x > WIDTH - BPIECE)
        pos.x = 0.f;

    if(!checkCollisions(pos)) {
        BodyPiece* b = body.back();
        b->setPosition(pos);
        body.push_front(b);
        body.pop_back();

        return true;
    }

    return false;
}

bool Pj::moveLeft() {
    sf::Vector2f pos = body.front()->getPosition();

    pos.x -= BPIECE;
    if(pos.x < 0)
        pos.x = WIDTH - BPIECE;

    if(!checkCollisions(pos)) {
        BodyPiece* b = body.back();
        b->setPosition(pos);
        body.push_front(b);
        body.pop_back();

        return true;
    }

    return false;
}

bool Pj::moveDown() {
    sf::Vector2f pos = body.front()->getPosition();

    pos.y += BPIECE;
    if(pos.y > HEIGHT - BPIECE)
        pos.y = 0;

    if(!checkCollisions(pos)) {
        BodyPiece* b = body.back();
        b->setPosition(pos);
        body.push_front(b);
        body.pop_back();

        return true;
    }

    return false;
}

void Pj::draw(sf::RenderWindow& window) const {

    // head
    BodyPiece* b = body[0];
    b->setTextureRect(sf::IntRect(80, 0, 40, 40));
    switch(direction) {
        case UP:    b->setRotation(-90.f); b->setScale(1.f, 1.f);  break;
        case RIGHT: b->setRotation(0.f);   b->setScale(1.f, 1.f);  break;
        case LEFT:  b->setRotation(0.f);   b->setScale(-1.f, 1.f); break;
        case DOWN:  b->setRotation(90.f);  b->setScale(1.f, 1.f);  break;
    }
    window.draw(*b);

    // body
    // tail


    // ugly old method

    sf::RectangleShape piece;
    piece.setSize(sf::Vector2f(BPIECE, BPIECE));
    sf::Color color;
    int aux = 0;

    for(unsigned int i = 1; i < body.size(); ++i) {
        color.r = color.g = color.b = 255 - aux;
        piece.setFillColor(color);
        if(aux < MAXBPIECES)
            aux++;
        piece.setPosition(body[i]->getPosition());
        window.draw(piece);
    }
}

void Pj::grow() {
    BodyPiece* b = new BodyPiece;
    b->setTexture(texture);
    b->setPosition(body.back()->getPosition());
    b->setOrigin(BPIECE / 2.f, BPIECE / 2.f);
    body.push_back(b);
}

bool Pj::checkCollisions(const sf::Vector2f& v) const {
    for(unsigned int i = 1; i < body.size(); ++i)
        if(v == body[i]->getPosition())
            return true;

    return false;
}

Pj::~Pj() {
    for(unsigned int i = 0; i < body.size(); ++i)
        delete body[i];
}
