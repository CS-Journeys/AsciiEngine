/*
 * test_game.cpp
 * 
 * Simple example game to test the AsciiEngine++'s capabilities
*/

#include "../AsciiEngine/Engine.h"

GameObject player; //Player game object
GameObject obj2;

int countDown; //Countdown variable

//onLoad function executes only once 
// the start of the program execution
void onLoad() {
    countDown = 2000;

    //Set player position
    player.x = 3;
    player.y = 3;

    obj2.x = 4;
    obj2.y = 4;

    obj2.sprite = '@';

    //Set game screen width/height
    Window.SCREEN_WIDTH = 20;
    Window.SCREEN_HEIGHT = 10;

    //Read in ascii art sprite from input file
    ifstream spriteFile;
    char c;

    //Read in sprite from file
    player.readSprite("Test Files/art.txt", 5);
}

//Update method executes every frame
// of the program execution
void Update() {
    //Subtract countdown variable by the time (in milli-seconds)
    countDown -= runTime.getTime();

    //Key user input (WASD)
    if (Input.keyPress('W')) {
        player.y--;
    } else if (Input.keyPress('S')) {
        player.y++;
    } else if (Input.keyPress('A')) {
        player.x--;
    } else if (Input.keyPress('D')) {
        player.x++;
    }

    if (Input.keyPress('Q')) {
        Window.quit();
    }

    //Move object relative to player
    if (countDown <= 0) {
        obj2.moveRelativeTo(player, 5, 5);

        countDown = 2000;
    }

    //Spawn player in the scene
    Window.spawnObj(player);
    Window.spawnObj(obj2);
}