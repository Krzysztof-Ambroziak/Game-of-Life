#ifndef GAMEOFLIFE_SETTINGS_H
#define GAMEOFLIFE_SETTINGS_H

#include <QWidget>
#include <QAbstractButton>
#include <QSpinBox>
#include "model/abstractmodel.h"
#include "controller/actions.h"

class Settings: public QWidget {
    Q_OBJECT

public:
    explicit Settings(const AbstractModel* const model, QWidget *parent = nullptr);
    
    void connectAction(Actions* actions);
    
    int randomFactor() const;

signals:

public slots:

private:
    const AbstractModel* const model;
    
    QAbstractButton* const nextStepBtn;
    
    QSpinBox* const randomFactorSB;
    
    QAbstractButton* const generateBtn;
    
    QAbstractButton* const simulateBtn;
};

#endif // GAMEOFLIFE_SETTINGS_H
