#include "gameoflifeapplication.h"

GameOfLifeApplication::GameOfLifeApplication(int& argc, char** argv):
        QApplication(argc, argv),
        guiService(&model) {}

void GameOfLifeApplication::show() {
    guiService.show();
}
