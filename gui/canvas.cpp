#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

Canvas::Canvas(const AbstractModel* const model, QWidget* parent):
        QWidget(parent),
        model(model) {
    const int width = (model->getCellSize() + 1) * model->getColumns() + 1;
    const int height = (model->getCellSize() + 1) * model->getRows() + 1;
    setMinimumSize(width, height);
}

void Canvas::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setPen(Qt::lightGray);
    drawGrid(&painter);
}

void Canvas::drawGrid(QPainter* painter) {
    drawHorizontalLines(painter);
    drawVerticalLines(painter);
}

void Canvas::drawHorizontalLines(QPainter* painter) {
    const int cellSizeInc = model->getCellSize() + 1;
    for(int i = 0; i <= model->getRows(); ++i) {
        const int y = i * cellSizeInc;
        painter->drawLine(0, y, width(), y);
    }
}

void Canvas::drawVerticalLines(QPainter* painter) {
    const int cellSizeInc = model->getCellSize() + 1;
    for(int i = 0; i <= model->getColumns(); ++i) {
        const int x = i * cellSizeInc;
        painter->drawLine(x, 0, x, height());
    }
}
