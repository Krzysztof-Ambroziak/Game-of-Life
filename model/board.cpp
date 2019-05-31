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

Board::~Board() {
    delete[] cells;
}

int Board::index(int row, int column) const {
    return (row + 1) * (columns + 2) + column + 1;
}
