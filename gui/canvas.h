#ifndef GAMEOFLIFE_CANVAS_H
#define GAMEOFLIFE_CANVAS_H

#include <QWidget>
#include "controller/actions.h"
#include "model/abstractmodel.h"

class Canvas: public QWidget {
    Q_OBJECT

public:
    explicit Canvas(const AbstractModel* const model, QWidget* parent = nullptr);
    
    void connectAction(Actions* actions);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    
    void paintEvent(QPaintEvent* event) override;

private:
    void drawCells(QPainter* painter);
    
    void drawGrid(QPainter* painter);
    
    void drawHorizontalLines(QPainter* painter);
    
    void drawVerticalLines(QPainter* painter);

private:
    const AbstractModel* const model;

signals:
    void clicked(int x, int y);

public slots:
};

#endif // GAMEOFLIFE_CANVAS_H
