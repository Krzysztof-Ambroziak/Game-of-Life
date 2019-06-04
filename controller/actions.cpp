#include "actions.h"
#include "gameoflifeapplication.h"
#include <QDebug>

Actions::Actions(GameOfLifeApplication* application, QObject* parent):
    QObject(parent),
    application(application) {}

void Actions::changeCell(int x, int y) {
    Model* model = application->getModel();
    int cellSizeInc = model->getCellSize() + 1;
    
    if(x % cellSizeInc && y % cellSizeInc) {
        model->changeLife(y / cellSizeInc, x / cellSizeInc);
        application->getGuiService()->update();
    }
}
