/*
 * test_game.cpp
 * 
 * Simple example game to test the AsciiEngine++'s capabilities
*/

#include "AsciiEngine/Engine.h"

GameObject player; //Player game object
int countDown; //Countdown variable

//onLoad function executes only once 
// the start of the program execution
void onLoad() {
    countDown = 2000;
    
    //Set player position
    player.x = 3;
    player.y = 3;

    //Set player appearance
    player.pt = '#';

    //Set game screen width/height
    Window.SCREEN_WIDTH = 10;
    Window.SCREEN_HEIGHT = 5;
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

    //When countdown hits 0 (every 2 seconds)
    if (countDown <= 0) {
        //Increment player character value
        //Will likely cause some funky stuff
        player.pt++; 

        Window.SCREEN_WIDTH++;
        Window.SCREEN_HEIGHT = Window.SCREEN_WIDTH / 2;

        //Reset countdown
        countDown = 2000;
    }

    //Spawn player in the scene
    Window.spawnObj(player.x, player.y, player.pt);
}