/*
 * game_ext.cpp
 * 
 * Driver for the game inputted into the engine
*/

#include "Engine.h"

void exec();

int main() {
    exec();

    return 0;
}

void exec() {
    onLoad();
    //Note: Using system() is bad practice and
        // should be changed later
    system("cls");

    while (!Window.done) {
        Window.initScreen();
        Update();
        
        Window.drawScreen(cout);
    }
}