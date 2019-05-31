#include "controller/gameoflifeapplication.h"

int main(int argc, char *argv[]) {
    GameOfLifeApplication application(argc, argv);
    
    return application.exec();
}
