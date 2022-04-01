//
// Created by Sigve Langva on 3/31/2022.
//

#include "Direction.h"

Direction::Direction(int x, int y, int maxY) : x(x), y(y), maxY(maxY){}

int Direction::getX() const {
    return x;
}

void Direction::setX() {
    Direction::x *= -1;

}

int Direction::getY() const {
    return y;
}

void Direction::setY() {
    Direction::y *= -1;
}

int Direction::getMaxY() {
    return maxY;
}



