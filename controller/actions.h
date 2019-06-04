#ifndef GAMEOFLIFE_ACTIONS_H
#define GAMEOFLIFE_ACTIONS_H

#include <QObject>

class GameOfLifeApplication;

class Actions: public QObject {
    Q_OBJECT

public:
    explicit Actions(GameOfLifeApplication* application, QObject *parent = nullptr);

signals:

public slots:
    void changeCell(int x, int y);

private:
    GameOfLifeApplication* application;
};

#endif // GAMEOFLIFE_ACTIONS_H
