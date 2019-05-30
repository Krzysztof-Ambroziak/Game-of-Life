#ifndef GAMEOFLIFE_MODEL_H
#define GAMEOFLIFE_MODEL_H

#include "board.h"

class Model {
public:
    Model(int rows = DEFAULT_ROWS, int columns = DEFAULT_COLUMNS);
    
    ~Model();

private:
    static const int DEFAULT_ROWS = 30;
    
    static const int DEFAULT_COLUMNS = 50;
    
    static const int DEFAULT_CELL_SIZE = 8;
    
    int cellSize;
    
    Board* board;
};

#endif // GAMEOFLIFE_MODEL_H
