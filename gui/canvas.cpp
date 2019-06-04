#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>

Canvas::Canvas(const AbstractModel* const model, QWidget* parent):
        QWidget(parent),
        model(model) {
    const int width = (model->getCellSize() + 1) * model->getColumns() + 1;
    const int height = (model->getCellSize() + 1) * model->getRows() + 1;
    setMinimumSize(width, height);
}

void Canvas::connectAction(Actions* actions) {
    QObject::connect(this, SIGNAL(clicked(int, int)), actions, SLOT(changeCell(int, int)));
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    emit clicked(event->x(), event->y());
}

void Canvas::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    drawCells(&painter);
    drawGrid(&painter);
}

void Canvas::drawCells(QPainter* painter) {
    const int rows = model->getRows();
    const int columns = model->getColumns();
    const int cellSizeInc = model->getCellSize() + 1;
    
    for(int row = 0; row < rows; ++row) {
        for(int column = 0; column < columns; ++column) {
            if(model->getLife(row, column) == ALIVE) {
                painter->fillRect(column * cellSizeInc, row * cellSizeInc, cellSizeInc, cellSizeInc, Qt::black);
            }
        }
    }
}

void Canvas::drawGrid(QPainter* painter) {
    painter->setPen(Qt::lightGray);
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
