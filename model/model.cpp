#include "model.h"

Model::Model(int rows, int columns):
        cellSize(DEFAULT_CELL_SIZE),
        board(new Board(rows, columns)) {}

Model::~Model() {
    delete board;
}
