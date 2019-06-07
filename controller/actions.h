#ifndef GAMEOFLIFE_ACTIONS_H
#define GAMEOFLIFE_ACTIONS_H

#include <QObject>
#include <QRandomGenerator>

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
    
    void clearBoard();
    
    void nextStep();
    
    void generateCells();
    
    void simulateStart();

private:
    GameOfLifeApplication* const application;
    
    QRandomGenerator generator;
};

#endif // GAMEOFLIFE_ACTIONS_H
