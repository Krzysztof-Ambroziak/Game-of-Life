#ifndef GAMEOFLIFE_GUISERVICE_H
#define GAMEOFLIFE_GUISERVICE_H

#include "canvas.h"
#include "mainframe.h"

class GuiService {
public:
    GuiService();
    
    void show() {
        mainFrame.show();
    }

public:
    Canvas* canvas;
    
    MainFrame mainFrame;
};

#endif // GAMEOFLIFE_GUISERVICE_H
