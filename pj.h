#ifndef PJ_H
#define PJ_H

#include <SFML/Graphics.hpp>
#include <deque>
#include "globals.h"

class Food;
class Score;

class Pj {
    class BodyPiece;
public:
    typedef std::deque<BodyPiece> Body;
    enum Direction {UP, RIGHT, LEFT, DOWN};

    Pj(int x = BPIECE, int y = BPIECE);

    void readInput(const sf::Event& event);
    bool update(Food& food, Score& score);
    const Body& getBody() const;
    void draw(sf::RenderWindow& window) const;
    void setDirection(const Direction& dir);
    void grow();
    bool checkCollisions(const BodyPiece& bp) const;
private:
    class BodyPiece {
    public:
        BodyPiece(int x, int y);

        const sf::Vector2i& coords() const;
        sf::Vector2i& coords();
    private:
        sf::Vector2i _coords;
    };

    Direction direction;
    Body body;

    bool moveUp();
    bool moveRight();
    bool moveLeft();
    bool moveDown();
};

inline Pj::BodyPiece::BodyPiece(int x, int y) : _coords(x, y) {}
inline const sf::Vector2i& Pj::BodyPiece::coords() const { return _coords; }
inline       sf::Vector2i& Pj::BodyPiece::coords()       { return _coords; }

inline const Pj::Body& Pj::getBody() const { return body; }
inline void  Pj::setDirection(const Direction& dir) {
    direction = dir;
}

#endif
