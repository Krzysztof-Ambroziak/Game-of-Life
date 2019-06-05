#include "actions.h"
#include "gameoflifeapplication.h"

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

void Actions::nextStep() {
    updateAliveNeighbours();
    updateBoard();
}

void Actions::updateAliveNeighbours() {
    Model* const model = application->getModel();
    const int rows = model->getRows();
    const int columns = model->getColumns();
    
    for(int row = 0; row < rows; ++row) {
        for(int column = 0; column < columns; ++column) {
            const int aliveNeighbours = model->computeAliveNeighbours(row, column);
            model->setAliveNeighbours(row, column, aliveNeighbours);
        }
    }
}

void Actions::updateBoard() {
    Model* const model = application->getModel();
    GuiService* const guiService = application->getGuiService();
    const int rows = model->getRows();
    const int columns = model->getColumns();
    
    for(int row = 0; row < rows; ++row) {
        for(int column = 0; column < columns; ++column) {
            const int aliveNeighbours = model->getAliveNeighbours(row, column);
            const Life life = model->getLife(row, column);
            
            if((life == DEAD && aliveNeighbours == 3) || (life == ALIVE && (aliveNeighbours < 2 || aliveNeighbours > 3))) {
                model->changeLife(row, column);
            }
        }
    }
    guiService->update();
}
