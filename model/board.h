#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H

#include "cell.h"

class Board {
public:
    Board(int rows, int columns);
    
    int getRows() const;
    
    int getColumns() const;
    
    Life getLife(int row, int column) const;
    
    void setLife(int row, int column, Life life);
    
    int computeAliveNeighbours(int row, int column) const;
    
    int getAliveNeighbours(int row, int column) const;
    
    void setAliveNeighbours(int row, int column, int aliveNeighbours);
    
    ~Board();

private:
    int index(const int& row, const int& column) const;

private:
    const int rows;
    
    const int columns;
    
    Cell* const cells;
};

#endif // GAMEOFLIFE_BOARD_H
