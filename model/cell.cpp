#include "cell.h"

Life Cell::getLife() const {
    return life;
}

void Cell::setLife(Life life) {
    this->life = life;
}

int Cell::getAliveNeighbours() const {
    return aliveNeighbours;
}

void Cell::setAliveNeighbours(int aliveNeighbours) {
    this->aliveNeighbours = aliveNeighbours;
}
