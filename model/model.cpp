#include "model.h"

Model::Model(int rows, int columns):
        cellSize(Model::DEFAULT_CELL_SIZE),
        board(new Board(rows, columns)) {}

int Model::getRows() const {
    return board->getRows();
}

int Model::getColumns() const {
    return board->getColumns();
}

int Model::getCellSize() const {
    return cellSize;
}

Life Model::getLife(int row, int column) const {
    return board->getLife(row, column);
}

void Model::setLive(int row, int column, Life life) {
    board->setLife(row, column, life);
}

void Model::changeLife(int row, int column) {
    Life life = board->getLife(row, column);
    if(life == Life::DEAD) {
        board->setLife(row, column, Life::ALIVE);
    }
    else {
        board->setLife(row, column, Life::DEAD);
    }
}

int Model::computeAliveNeighbours(int row, int column) const {
    return board->computeAliveNeighbours(row, column);
}

int Model::getAliveNeighbours(int row, int column) const {
    return board->getAliveNeighbours(row, column);
}

void Model::setAliveNeighbours(int row, int column, int aliveNeighbours) {
    board->setAliveNeighbours(row, column, aliveNeighbours);
}

Model::~Model() {
    delete board;
}
