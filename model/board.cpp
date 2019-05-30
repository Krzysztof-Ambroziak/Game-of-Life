#include "board.h"

Board::Board(int rows, int columns):
        rows(rows),
        columns(columns),
        cells(new Cell[(rows + 2) * (columns + 2)]) {}

Board::~Board() {
    delete[] cells;
}
