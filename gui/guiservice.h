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
    
    int getRandomFactor() const;
    
    void show();

public:
    Canvas* const canvas;
    
    Settings* const settings;
    
    MainFrame mainFrame;
};

#endif // GAMEOFLIFE_GUISERVICE_H
