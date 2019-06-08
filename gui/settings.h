#ifndef GAMEOFLIFE_SETTINGS_H
#define GAMEOFLIFE_SETTINGS_H

#include <QWidget>
#include <QAbstractButton>
#include <QSpinBox>
#include <QAbstractSlider>
#include <QLabel>
#include "model/abstractmodel.h"
#include "controller/actions.h"

class Settings: public QWidget {
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    
    void connectAction(Actions* actions);
    
    int randomFactor() const;

public slots:
    void clickableComponents();

public:
    static const int DEFAULT_SPEPS_PER_SECONDS = 1;

private:
    static const int MINIMUM_RANDOM_PERCENTAGE = 0;
    
    static const int MAXIMUM_RANDOM_PERCENTAGE = 100;
    
    static const int DEFAULT_RANDOM_PERCENTAGE = 20;
    
    static const int MINIMUM_SPEPS_PER_SECONDS = 1;
    
    static const int MAXIMUM_SPEPS_PER_SECONDS = 60;
    
    bool enabled = true;
    
    QAbstractButton* const clearBoardBtn;
    
    QAbstractButton* const nextStepBtn;
    
    QSpinBox* const randomFactorSB;
    
    QAbstractButton* const generateBtn;
    
    QAbstractSlider* const speedSl;
    
    QAbstractButton* const simulateBtn;
};

#endif // GAMEOFLIFE_SETTINGS_H
