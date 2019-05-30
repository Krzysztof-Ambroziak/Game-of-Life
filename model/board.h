#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H

#include "cell.h"

class Board {
public:
    Board(int rows, int columns);
    
    ~Board();

private:
    const int rows;
    
    const int columns;
    
    Cell* const cells;
};

#endif // GAMEOFLIFE_BOARD_H
