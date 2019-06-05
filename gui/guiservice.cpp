#include "guiservice.h"

GuiService::GuiService(const AbstractModel* const model):
        canvas(new Canvas(model)),
        settings(new Settings(model)),
        mainFrame(canvas, settings) {}

void GuiService::addActions(Actions* actions) {
    canvas->connectAction(actions);
    settings->connectAction(actions);
}

void GuiService::update() {
    canvas->update();
}

void GuiService::show() {
    mainFrame.show();
}
