#include "mainframe.h"
#include <QHBoxLayout>
#include <QScrollArea>

MainFrame::MainFrame(QWidget* canvas, QWidget* parent): QMainWindow(parent) {
    QWidget* central = new QWidget(this);
    QLayout* layout = new QHBoxLayout(central);
    QScrollArea* scrollArea = new QScrollArea(central);
    
    canvas->setParent(scrollArea);
    
    scrollArea->setWidget(canvas);
    layout->addWidget(scrollArea);
    central->setLayout(layout);
    setCentralWidget(central);
}
