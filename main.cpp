#include "controller/gameoflifeapplication.h"

int main(int argc, char *argv[]) {
    GameOfLifeApplication application(argc, argv);
    application.show();
    
    return application.exec();
}
