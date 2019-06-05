#include "settings.h"
#include <QVBoxLayout>
#include <QDebug>

Settings::Settings(const AbstractModel* const model, QWidget *parent):
        QWidget(parent),
        model(model),
        nextStepBtn(new QPushButton(">", this)) {
    QLayout* layout = new QVBoxLayout();
    layout->addWidget(nextStepBtn);
    setLayout(layout);
}

void Settings::connectAction(Actions* actions) {
    QObject::connect(nextStepBtn, SIGNAL(clicked()), actions, SLOT(nextStep()));
}
