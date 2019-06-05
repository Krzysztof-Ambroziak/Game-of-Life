#include "board.h"

Board::Board(int rows, int columns):
        rows(rows),
        columns(columns),
        cells(new Cell[(rows + 2) * (columns + 2)]) {}

int Board::getRows() const {
    return rows;
}

int Board::getColumns() const {
    return columns;
}

Life Board::getLife(int row, int column) const {
    return cells[index(row, column)].getLife();
}

void Board::setLife(int row, int column, Life life) {
    cells[index(row, column)].setLife(life);
}

int Board::computeAliveNeighbours(int row, int column) const {
    int aliveNeighbours = 0;
    int i = index(row, column);
    
    if(cells[i - columns - 3].getLife() == ALIVE) ++aliveNeighbours;
    if(cells[i - columns - 2].getLife() == ALIVE) ++aliveNeighbours;
    if(cells[i - columns - 1].getLife() == ALIVE) ++aliveNeighbours;
    if(cells[i           - 1].getLife() == ALIVE) ++aliveNeighbours;
    if(cells[i           + 1].getLife() == ALIVE) ++aliveNeighbours;
    if(cells[i + columns + 1].getLife() == ALIVE) ++aliveNeighbours;
    if(cells[i + columns + 2].getLife() == ALIVE) ++aliveNeighbours;
    if(cells[i + columns + 3].getLife() == ALIVE) ++aliveNeighbours;
    
    return aliveNeighbours;
}

int Board::getAliveNeighbours(int row, int column) const {
    return cells[index(row, column)].getAliveNeighbours();
}

void Board::setAliveNeighbours(int row, int column, int aliveNeighbours) {
    cells[index(row, column)].setAliveNeighbours(aliveNeighbours);
}

Board::~Board() {
    delete[] cells;
}

int Board::index(const int& row, const int& column) const {
    return (row + 1) * (columns + 2) + column + 1;
}
