#include "mainframe.h"
#include <QHBoxLayout>
#include <QScrollArea>

MainFrame::MainFrame(QWidget* canvas, QWidget* settings, QWidget* parent): QMainWindow(parent) {
    QWidget* central = new QWidget(this);
    QLayout* layout = new QHBoxLayout(central);
    QScrollArea* scrollArea = new QScrollArea(central);
    
    canvas->setParent(scrollArea);
    settings->setParent(central);
    
    scrollArea->setWidget(canvas);
    layout->addWidget(scrollArea);
    layout->addWidget(settings);
    central->setLayout(layout);
    setCentralWidget(central);
}
