/*
 * test_game.cpp
 * 
 * Simple example game to test the AsciiEngine++'s capabilities
*/

#include "../AsciiEngine/Engine.h"
#include <cmath>

GameObject player; //Player game object
GameObject object1; 

int countDown; //Countdown variable

//onLoad function executes only once 
// the start of the program execution
void onLoad() {
    countDown = 2000;
    
    //Set player position
    player.x = 1;
    player.y = 1;

    //Set object positions
    object1.x = 3;
    object1.y = 3;

    //Set game screen width/height
    Window.SCREEN_WIDTH = 20;
    Window.SCREEN_HEIGHT = 10;

    //Read in ascii art sprite from input file
    ifstream spriteFile;
    char c;

    //Read in sprites from file
    player.readSprite("Test Files/art.txt", 1, 4);
    object1.readSprite("Test Files/art.txt", 6, 7);
}

//Update method executes every frame
// of the program execution
void Update() {
    //Subtract countdown by the time (in milli-seconds)
    countDown -= runTime.getTime();

    //User input
    if (Input.keyPress('W')) {
        player.y--;
    } else if (Input.keyPress('S')) {
        player.y++;
    } else if (Input.keyPress('A')) {
        player.x--;
    } else if (Input.keyPress('D')) {
        player.x++;
    }

    //Quit Game
    if (Input.keyPress('Q')) {
        Window.quit();
    }

    //Move object relative to player
    if (countDown <= 0) {
        object1.moveRelativeTo(player, 5, 5);

        countDown = 2000;
    }

    //Spawn objects in the scene
    Window.spawnObj(player);
    Window.spawnObj(object1);
}