#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H

enum Life {
    DEAD,
    ALIVE
};

class Cell {
public:
    Life getLife() const;
    
    void setLife(Life life);
    
    int getAliveNeighbours() const;
    
    void setAliveNeighbours(int aliveNeighbours);

private:
    Life life;
    
    int aliveNeighbours;
};

#endif // GAMEOFLIFE_CELL_H
