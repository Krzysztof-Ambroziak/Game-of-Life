#ifndef GAMEOFLIFE_CANVAS_H
#define GAMEOFLIFE_CANVAS_H

#include <QWidget>
#include "model/abstractmodel.h"

class Canvas: public QWidget {
    Q_OBJECT

public:
    explicit Canvas(const AbstractModel* const model, QWidget* parent = nullptr);

private:
    const AbstractModel* const model;

signals:

public slots:
};

#endif // GAMEOFLIFE_CANVAS_H
