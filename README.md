# AsciiEngine++
AsciiEngine (or AsciiEngine++) is C++ game engine intended to make building command-line-based games easy.

Engine provides flexibility and self-modification capabilities for game projects. Can also be utilized for ascii command-line animations, as well as supports import of outside libraries within a user's own game project files.

**Open to any suggestions!**

```
-------------------------------------------------------------------------------------

   _____                 __ __            ___________               __               
  /  _  \   ______ ____ |__|__|           \_   _____/ ____    ____ |__| ____   ____  
 /  /_\  \ /  ___// ___\|  |  |            |   |____ /    \  / ___\|  |/  __\_/ ___\ 
/    |    \\___ \\  \___|  |  |            |   _____|   |  \/  /___|  |   |  \ \___ 
\___/ \_  //_____>\_____|__|__|           /_________|___|__/\___  /|__|___|__/\____| 
                                __          __     
                             __|  |__    __|  |__ 
                            |__    __|  |__    __| 
                               |__|        |__|    

-------------------------------------------------------------------------------------
```

## Documentation

#### Quick Links

 - [Getting Started](#Getting-Started)
 - [Compiling Your First Game](#Compiling-Your-First-Game)
 - [Modifying the Engine](#Modifying-the-Engine)
 - [Scripting Reference](#Scripting-Reference)

# Getting Started
**Every AsciiEngine game file must:**
1. Be a [C++](https://www.cplusplus.com/) file extension (*.cpp*)
2. Include `AsciiEngine/Engine.h` at the top of the game
3. Have an `onLoad()` and `Update()` method (See [Scripting Reference](#Scripting-Reference) for explanation of methods)

Example:
```c++
#include "AsciiEngine/Engine.h"

//onLoad function executes only once 
// the start of the program execution
void onLoad() {
    //Do something
}

//Update method executes every frame
// of the program execution
void Update() {
    //Do something else
}
```

# Compiling Your First Game
To compile and run your first game, launch the `AsciiEngine.exe` file. You will be prompted for the path of the file, and then the name of the game. After that, a (*.exe*) file will be created with the specified name of your game. Launch that, and your game is ready to play!

# Modifying the Engine
There is a wide array of objects and functions that exist for the engine. 

The `AsciiEngine/Engine.h` file is the main engine file. The `AsciiEngine/read_file.cpp` is the main driver file for the engine, which reads in an outside game file and builds that file into a game. All project files are (hopefully) commented well and should give an understanding for each file's purpose.

Detailed explanation of each main engine feature/function can be found in the [Scripting Reference](#Scripting-Reference). That is also a good place to start.

# Scripting Reference
AsciiEngine++ offers a wide amount of custom scripting for a user's game. This section explains the details of each major method and object available to the user for making a game.

#### onLoad()
`onLoad` is called at the first frame of execution. 

This function is used to initialize certain variables for the start of a game.

```c++
GameObject obj;

void onLoad() {

    obj.x = 1;
    obj.y = 1;

    obj.pt = '%';
}
```

#### Update()
`Update` is called at every frame of execution of a game. 

This function allows the game to be continuously running.

```c++
GameObject obj;

void Update() {
    obj.x++;

    if (obj.x > obj.y) {
        obj.x = 0;
    }
}
```

#### GameObject class
The GameObject class is the basis for all objects within the game.

Public Methods:
 - [collision()](#collision())

##### GameObject class functions

##### collision()
`collision(GameObject)` is a GameObject class function that returns true if two GameObjects are colliding.

```c++
GameObject obj1, obj2;

void onLoad() {
    obj1.x = 3;
    obj2.y = 4;

    obj2.x = 3;
    obj2.y = 4;
}

void Update() {

}
```

#### Window/Screen class
Window is an engine object of the Screen class.

Public Methods:
 - [initScreen()](#initScreen())
 - [clearScreen()](#clearScreen())
 - [drawScreen()](#drawScreen())
 - [spawnObj()](#spawnObj())
 - [quit()](#quit())

##### Screen class functions

##### initScreen()
`initScreen()` is a Screen class function that initializes/resets the game window.

This is called automatically by the engine at the start of each execution frame, and is not recommended to be called by a user inside of their own game script.

##### clearScreen()
`clearScreen()` is a Screen class function that clears the console window.

This function is used by the [drawScreen()](#drawScreen()) function for drawing the game window.

##### drawScreen()
`drawScreen(ostream& out)` is a Screen class function that draws the game window onto an output stream (cout by default) at the end of each execution frame.

This function is called automatically by the engine at every execution frame, and is *not* recommended to be called inside of a user's own game.

##### spawnObj()
`spawnObj(int& xPos, int& yPos, char c)` is a Screen class function that spawns an object character onto the screen at a specified position.

If the position is less than or greater than the screen dimensions, the position is automatically wrapped back around to fit inside the game window when called.

```c++

GameObject obj1;

void onLoad() {
    obj1.x = 5;
    obj1.y = 3;

    obj1.pt = '@';
}

void Update() {
    Window.spawnObj(obj1.x, obj1.y, obj1.pt);
}
```

##### quit()
`quit()` is a Screen class function that ends game execution.

*Highly* recommended that this function is called somewhere in the user's `Update()` function (else the game will be running on an infinite loop).

```c++

int i = 0;

void Update() {
    i++;

    if (i >= 1000) {
        Window.quit(); //End game execution
    }
}
```

#### Input/Keyboard class
Input is an engine object of the Keyboard class.

Public Methods:
 - [keyDown()](#keyDown())
 - [keyUp()](#keyUp())
 - [keyPress()](#keyPress())

##### keyDown()
`keyDown(char key)` is a Keyboard class function that returns true if a key is being held down.

Currently, the key char being passed to the function must be an uppercase, alphabetic character.

```c++

GameObject obj1;

void onLoad() {
    obj1.x = 0;
    obj1.y = 0;

    obj1.pt = '@';
}

void Update() {
    //Increases y position by 1 when W key is held down
    if (Input.keyDown('W')) {
        obj1.y++;
    }

    Window.spawnObj(obj1.x, obj1.y, obj1.pt);
}
```

##### keyUp()
`keyUp(char key)` is a Keyboard class function that returns true if a key is not being held down.

##### keyPress()
`keyPress(char key)` is a Keyboard class function that returns true if a key is pressed once.

Different from keyDown in that instead of returning true when a key is held down, it returns true when a key is pressed after being in a state of release. Will return false if a key is held down after already being pressed.

#### runTime/Time class
runTime is an engine object of the Time class.

Public Methods:
 - [getTime()](#getTime())

##### getTime()
`getTime()` is a Time class function that returns the time in milli-seconds since the last frame.

Useful when wanting to have a countdown to a certain execution in a game.

```c++
int countDown = 2000;

void Update() {
    countDown -= runTime.getTime();

    //If 2 seconds have elapsed
    if (countDown <= 0) {
        cout << "2 seconds have passed!" << endl;

        countDown = 2000;
    }
}
```