#include "model.h"

Model::Model(int rows, int columns):
        cellSize(DEFAULT_CELL_SIZE),
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

Model::~Model() {
    delete board;
}
