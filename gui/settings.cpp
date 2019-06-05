#include "settings.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>

Settings::Settings(const AbstractModel* const model, QWidget *parent):
        QWidget(parent),
        model(model),
        nextStepBtn(new QPushButton("Next step", this)),
        randomFactorSB(new QSpinBox(this)),
        generateBtn(new QPushButton("Generate", this)),
        simulateBtn(new QPushButton("Simulate", this)) {
    randomFactorSB->setRange(0, 100);
    randomFactorSB->setValue(20);
    
    QBoxLayout* layout = new QVBoxLayout(this);
    QFormLayout* randomLayout = new QFormLayout;
    
    randomLayout->addRow("Random [%]:", randomFactorSB);
    
    layout->addWidget(nextStepBtn);
    layout->addLayout(randomLayout);
    layout->addWidget(generateBtn);
    layout->addWidget(simulateBtn);
    layout->addStretch();
    
    setLayout(layout);
}

void Settings::connectAction(Actions* actions) {
    QObject::connect(nextStepBtn, SIGNAL(clicked()), actions, SLOT(nextStep()));
    QObject::connect(generateBtn, SIGNAL(clicked()), actions, SLOT(generateCells()));
}

int Settings::randomFactor() const {
    return randomFactorSB->value();
}
