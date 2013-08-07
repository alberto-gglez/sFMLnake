#include "pj.h"
#include "food.h"
#include "score.h"

Pj::Pj(float x, float y)
    : actualDir(RIGHT), nextDir(RIGHT)
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
            nextDir = UP;
        if(event.key.code == sf::Keyboard::Right)
            nextDir = RIGHT;
        if(event.key.code == sf::Keyboard::Left)
            nextDir = LEFT;
        if(event.key.code == sf::Keyboard::Down)
            nextDir = DOWN;
        // for testing
        if(event.key.code == sf::Keyboard::Space)
            grow();
    }
}

bool Pj::update(Food& food, Score& score) {
    bool noCollisions;

    switch(nextDir) {
        case UP:    noCollisions = moveUp();    break;
        case RIGHT: noCollisions = moveRight(); break;
        case LEFT:  noCollisions = moveLeft();  break;
        case DOWN:  noCollisions = moveDown();  break;
    }
    actualDir = nextDir;

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
    if(pos.y < 20.f)
        pos.y = HEIGHT - BPIECE + 20.f;

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
    if(pos.x > WIDTH - BPIECE + 20.f)
        pos.x = 20.f;

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
    if(pos.x < 20.f)
        pos.x = WIDTH - BPIECE + 20.f;

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
    if(pos.y > HEIGHT - BPIECE + 20.f)
        pos.y = 20.f;

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
    switch(actualDir) {
        case UP:    b->setRotation(-90.f); b->setScale(1.f, 1.f);  break;
        case RIGHT: b->setRotation(0.f);   b->setScale(1.f, 1.f);  break;
        case LEFT:  b->setRotation(0.f);   b->setScale(-1.f, 1.f); break;
        case DOWN:  b->setRotation(90.f);  b->setScale(1.f, 1.f);  break;
    }
    window.draw(*b);

    // body
    for(unsigned int i = 1; i < body.size() - 1; ++i) {
        Direction dirPrev = prevPiecePos(i), dirPos = prevPiecePos(i + 1);
        b = body[i];
        b->setTextureRect(sf::IntRect(40, 0, 40, 40));

        switch(dirPrev) {
            case UP: {
                switch(dirPos) {
                    case UP:  b->setTextureRect(sf::IntRect(40, 0, 40, 40));  b->setRotation(-90.f); b->setScale(1.f, 1.f);  break;
                    case RIGHT: b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f);   b->setScale(-1.f, 1.f); break;
                    case LEFT:  b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f);   b->setScale(1.f, 1.f);  break;
                    default: break;
                }
                break;
            }
            case RIGHT: {
                switch(dirPos) {
                    case RIGHT: b->setTextureRect(sf::IntRect(40, 0, 40, 40));  b->setRotation(0.f); b->setScale(1.f, 1.f);  break;
                    case UP:    b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f); b->setScale(1.f, -1.f); break;
                    case DOWN:  b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f); b->setScale(1.f, 1.f);  break;
                    default: break;
                }
                break;
            }
            case LEFT: {
                switch(dirPos) {
                    case LEFT: b->setTextureRect(sf::IntRect(40, 0, 40, 40)); b->setRotation(0.f); b->setScale(-1.f, 1.f); break;
                    case DOWN: b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f); b->setScale(-1.f, 1.f); break;
                    case UP: b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f); b->setScale(-1.f, -1.f); break;
                    default: break;
                }
                break;
            }
            case DOWN: {
                switch(dirPos) {
                    case DOWN: b->setTextureRect(sf::IntRect(40, 0, 40, 40)); b->setRotation(90.f); b->setScale(1.f, 1.f); break;
                    case RIGHT: b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f); b->setScale(-1.f, -1.f); break;
                    case LEFT: b->setTextureRect(sf::IntRect(120, 0, 40, 40)); b->setRotation(0.f); b->setScale(1.f, -1.f); break;
                    default: break;
                }
                break;
            }
        }

        window.draw(*b);
    }

    // tail
    int n = body.size() - 1;
    b = body[n];
    b->setTextureRect(sf::IntRect(0, 0, 40, 40));
    switch(prevPiecePos(n)) {
        case UP:    b->setRotation(-90.f); b->setScale(1.f, 1.f);  break;
        case RIGHT: b->setRotation(0.f);   b->setScale(1.f, 1.f);  break;
        case LEFT:  b->setRotation(0.f);   b->setScale(-1.f, 1.f); break;
        case DOWN:  b->setRotation(90.f);  b->setScale(1.f, 1.f);  break;
    }
    window.draw(*b);
}

void Pj::grow() {
    BodyPiece* b = new BodyPiece;
    b->setTexture(texture);
    b->setPosition(body.back()->getPosition());
    b->setOrigin(BPIECE / 2.f, BPIECE / 2.f);
    body.push_back(b);
}

bool Pj::checkCollisions(const sf::Vector2f& v) const {
    for(unsigned int i = 1; i < body.size() - 1; ++i)
        if(v == body[i]->getPosition())
            return true;

    return false;
}

Pj::~Pj() {
    for(unsigned int i = 0; i < body.size(); ++i)
        delete body[i];
}

Pj::Direction Pj::prevPiecePos(unsigned int i) const {
    sf::Vector2f pos = body[i]->getPosition() - body[i - 1]->getPosition();

    if(pos.x == 0) {
        if(pos.y == HEIGHT - 40.f)
            return DOWN;
        else if(pos.y == -HEIGHT + 40.f)
            return UP;
        else if(pos.y > 0)
            return UP;
        else
            return DOWN;
    } else {
        if(pos.x == WIDTH - 40.f)
            return RIGHT;
        else if(pos.x == -WIDTH + 40.f)
            return LEFT;
        else if(pos.x > 0)
            return LEFT;
        else
            return RIGHT;
    }
}
