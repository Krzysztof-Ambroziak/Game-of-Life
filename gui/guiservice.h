#ifndef GAMEOFLIFE_GUISERVICE_H
#define GAMEOFLIFE_GUISERVICE_H

#include "model/abstractmodel.h"
#include "controller/actions.h"
#include "canvas.h"
#include "settings.h"
#include "mainframe.h"

class GuiService {
public:
    GuiService(const AbstractModel* const model);
    
    void addActions(Actions* actions);
    
    void update();
    
    void show();

public:
    Canvas* const canvas;
    
    Settings* settings;
    
    MainFrame mainFrame;
};

#endif // GAMEOFLIFE_GUISERVICE_H
