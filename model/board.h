#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H

#include "cell.h"

class Board {
public:
    Board(int rows, int columns);
    
    int getRows() const;
    
    int getColumns() const;
    
    Life getLife(int row, int column) const;
    
    ~Board();

private:
    int index(int row, int column) const;

private:
    const int rows;
    
    const int columns;
    
    Cell* const cells;
};

#endif // GAMEOFLIFE_BOARD_H
