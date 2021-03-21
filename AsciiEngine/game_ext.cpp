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

    while (!Window.done) {
        Window.initScreen();
        Update();
        
        Window.drawScreen(cout);
    }
}