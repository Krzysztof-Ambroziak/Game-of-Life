#ifndef GAMEOFLIFE_GAMEOFLIFEAPPLICATION_H
#define GAMEOFLIFE_GAMEOFLIFEAPPLICATION_H

#include <QApplication>
#include "gui/guiservice.h"
#include "model/model.h"

class GameOfLifeApplication: public QApplication {
    Q_OBJECT

public:
    explicit GameOfLifeApplication(int& argc, char** argv);
    
    void show();

private:
    Model model;
    
    GuiService guiService;

signals:

public slots:
};

#endif // GAMEOFLIFE_GAMEOFLIFEAPPLICATION_H
