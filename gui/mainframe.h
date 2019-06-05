#ifndef GAMEOFLIFE_MAINFRAME_H
#define GAMEOFLIFE_MAINFRAME_H

#include <QMainWindow>

class MainFrame: public QMainWindow {
    Q_OBJECT

public:
    explicit MainFrame(QWidget* canvas, QWidget* settings, QWidget* parent = nullptr);

signals:

public slots:
};

#endif // GAMEOFLIFE_MAINFRAME_H
