#ifndef GAMEOFLIFE_ACTIONS_H
#define GAMEOFLIFE_ACTIONS_H

#include <QObject>

class GameOfLifeApplication;

class Actions: public QObject {
    Q_OBJECT

public:
    explicit Actions(GameOfLifeApplication* application, QObject *parent = nullptr);

private:
    void updateAliveNeighbours();
    
    void updateBoard();

signals:

public slots:
    void changeCell(int x, int y);
    
    void nextStep();
    
    void generateCells();

private:
    GameOfLifeApplication* const application;
};

#endif // GAMEOFLIFE_ACTIONS_H
