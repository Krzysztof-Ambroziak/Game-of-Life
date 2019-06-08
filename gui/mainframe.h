#ifndef GAMEOFLIFE_MAINFRAME_H
#define GAMEOFLIFE_MAINFRAME_H

#include <QMainWindow>

class MainFrame: public QMainWindow {
public:
    explicit MainFrame(QWidget* canvas, QWidget* settings, QWidget* parent = nullptr);
};

#endif // GAMEOFLIFE_MAINFRAME_H
