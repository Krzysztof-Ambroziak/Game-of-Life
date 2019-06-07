#include "guiservice.h"

GuiService::GuiService(const AbstractModel* const model):
        canvas(new Canvas(model)),
        settings(new Settings),
        mainFrame(canvas, settings) {}

void GuiService::addActions(Actions* actions) {
    canvas->connectAction(actions);
    settings->connectAction(actions);
}

void GuiService::update() {
    canvas->update();
}

int GuiService::getRandomFactor() const {
    return settings->randomFactor();
}

void GuiService::show() {
    mainFrame.show();
}
