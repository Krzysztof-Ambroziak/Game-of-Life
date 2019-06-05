#ifndef GAMEOFLIFE_MODEL_H
#define GAMEOFLIFE_MODEL_H

#include "abstractmodel.h"
#include "board.h"

class Model: public AbstractModel {
public:
    Model(int rows = DEFAULT_ROWS, int columns = DEFAULT_COLUMNS);
    
    int getRows() const override;
    
    int getColumns() const override;
    
    int getCellSize() const override;
    
    Life getLife(int row, int column) const override;
    
    void changeLife(int row, int column);
    
    int computeAliveNeighbours(int row, int column) const;
    
    int getAliveNeighbours(int row, int column) const;
    
    void setAliveNeighbours(int row, int column, int aliveNeighbours);
    
    ~Model() override;

private:
    static const int DEFAULT_ROWS = 30;
    
    static const int DEFAULT_COLUMNS = 50;
    
    static const int DEFAULT_CELL_SIZE = 8;
    
    int cellSize;
    
    Board* board;
};

#endif // GAMEOFLIFE_MODEL_H
