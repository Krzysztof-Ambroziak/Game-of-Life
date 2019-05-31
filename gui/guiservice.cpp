#include "guiservice.h"

GuiService::GuiService(const AbstractModel* const model):
        canvas(new Canvas(model)),
        mainFrame(canvas) {}

void GuiService::show() {
    mainFrame.show();
}
