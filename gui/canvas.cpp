#include "canvas.h"

Canvas::Canvas(const AbstractModel* const model, QWidget* parent):
        QWidget(parent),
        model(model) {
    const int width = (model->getCellSize() + 1) * model->getColumns() + 1;
    const int height = (model->getCellSize() + 1) * model->getRows() + 1;
    setMinimumSize(width, height);
}
