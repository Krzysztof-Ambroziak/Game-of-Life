#include "settings.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>

Settings::Settings(QWidget *parent):
        QWidget(parent),
        clearBoardBtn(new QPushButton("Clear board", this)),
        nextStepBtn(new QPushButton("Next step", this)),
        randomFactorSB(new QSpinBox(this)),
        generateBtn(new QPushButton("Generate", this)),
        speedSl(new QSlider(Qt::Horizontal, this)),
        simulateBtn(new QPushButton("Simulate", this)) {
    simulateBtn->setCheckable(true);
    QLabel* spsLb = new QLabel(this);
    
    randomFactorSB->setRange(Settings::MINIMUM_RANDOM_PERCENTAGE, Settings::MAXIMUM_RANDOM_PERCENTAGE);
    randomFactorSB->setValue(Settings::DEFAULT_RANDOM_PERCENTAGE);
    speedSl->setRange(Settings::MINIMUM_SPEPS_PER_SECOND, Settings::MAXIMUM_SPEPS_PER_SECOND);
    spsLb->setNum(speedSl->value());
    spsLb->setAlignment(Qt::AlignRight);
    
    QObject::connect(speedSl, SIGNAL(valueChanged(int)), spsLb, SLOT(setNum(int)));
    QObject::connect(simulateBtn, SIGNAL(clicked()), this, SLOT(clickableComponents()));
    
    QBoxLayout* layout = new QVBoxLayout(this);
    QFormLayout* randomLayout = new QFormLayout;
    QFormLayout* speedLayout = new QFormLayout;
    
    randomLayout->addRow("Random [%]:", randomFactorSB);
    speedLayout->addRow("Speed:", speedSl);
    speedLayout->addRow("SPS:", spsLb);
    
    layout->addWidget(clearBoardBtn);
    layout->addWidget(nextStepBtn);
    layout->addLayout(randomLayout);
    layout->addWidget(generateBtn);
    layout->addLayout(speedLayout);
    layout->addWidget(simulateBtn);
    layout->addStretch();
    
    setLayout(layout);
}

void Settings::connectAction(Actions* actions) {
    QObject::connect(clearBoardBtn, SIGNAL(clicked()), actions, SLOT(clearBoard()));
    QObject::connect(nextStepBtn, SIGNAL(clicked()), actions, SLOT(nextStep()));
    QObject::connect(generateBtn, SIGNAL(clicked()), actions, SLOT(generateCells()));
    QObject::connect(speedSl, SIGNAL(valueChanged(int)), actions, SLOT(speedChange(int)));
    QObject::connect(simulateBtn, SIGNAL(clicked()), actions, SLOT(timerTrigger()));
}

int Settings::randomFactor() const {
    return randomFactorSB->value();
}

void Settings::clickableComponents() {
    enabled = enabled == false;
    clearBoardBtn->setEnabled(enabled);
    nextStepBtn->setEnabled(enabled);
    randomFactorSB->setEnabled(enabled);
    generateBtn->setEnabled(enabled);
}
