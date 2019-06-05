#ifndef GAMEOFLIFE_SETTINGS_H
#define GAMEOFLIFE_SETTINGS_H

#include <QWidget>
#include <QPushButton>
#include "model/abstractmodel.h"
#include "controller/actions.h"

class Settings: public QWidget {
    Q_OBJECT

public:
    explicit Settings(const AbstractModel* const model, QWidget *parent = nullptr);
    
    void connectAction(Actions* actions);

signals:

public slots:

private:
    const AbstractModel* const model;
    
    QPushButton* nextStepBtn;
};

#endif // GAMEOFLIFE_SETTINGS_H
