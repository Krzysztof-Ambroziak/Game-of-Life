#include "gameoflifeapplication.h"

GameOfLifeApplication::GameOfLifeApplication(int& argc, char** argv):
        QApplication(argc, argv),
        guiService(&model),
        timer(new QTimer(this)),
        actions(this) {
    QObject::connect(timer, SIGNAL(timeout()), &actions, SLOT(nextStep()));
}

Model* GameOfLifeApplication::getModel() {
    return &model;
}

GuiService* GameOfLifeApplication::getGuiService() {
    return &guiService;
}

void GameOfLifeApplication::init() {
    timer->setInterval(Actions::spsToMsec(Settings::DEFAULT_SPEPS_PER_SECOND));
    guiService.addActions(&actions);
}

void GameOfLifeApplication::setInterval(int interval) {
    timer->setInterval(interval);
}

void GameOfLifeApplication::timerTrigger() {
    if(timer->isActive()) {
        timer->stop();
    }
    else {
        timer->start();
    }
}

void GameOfLifeApplication::show() {
    guiService.show();
}
