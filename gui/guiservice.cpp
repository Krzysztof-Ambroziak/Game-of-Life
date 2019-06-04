#include "guiservice.h"

GuiService::GuiService(const AbstractModel* const model):
        canvas(new Canvas(model)),
        mainFrame(canvas) {}

void GuiService::addActions(Actions* actions) {
    canvas->connectAction(actions);
}

void GuiService::update() {
    canvas->update();
}

void GuiService::show() {
    mainFrame.show();
}
