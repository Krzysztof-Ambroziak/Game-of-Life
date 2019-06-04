#include "gameoflifeapplication.h"

GameOfLifeApplication::GameOfLifeApplication(int& argc, char** argv):
        QApplication(argc, argv),
        guiService(&model),
        actions(this) {}

Model* GameOfLifeApplication::getModel() {
    return &model;
}

GuiService* GameOfLifeApplication::getGuiService() {
    return &guiService;
}

void GameOfLifeApplication::init() {
    guiService.addActions(&actions);
}

void GameOfLifeApplication::show() {
    guiService.show();
}
