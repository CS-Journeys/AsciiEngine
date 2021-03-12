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

[Getting Started](#Getting-Started)
[Using the Engine](#Using-the-Engine)
[Modifying the Engine](#Modifying-the-Engine)

# Getting Started
**A game project file must:**
1. Be a [C++](https://www.cplusplus.com/) file extension (*.cpp*)
2. Include `AsciiEngine/Engine.h` at the top of the game
3. Have an `onLoad()` and `Update()` method

Example:
```
#include "AsciiEngine/Engine.h"

//onLoad function executes only once 
// the start of the program execution
void onLoad() {
    //Do something
}

//Update method executes every frame
// of the program execution
void Update() {
    //Do something
}
```

# Using the Engine
To compile and run your first game, launch the `AsciiEngine.exe` file. You will be prompted for the path of the file, and then the name of the game. After that, a *.exe* file will be created with the specified name of your game. Launch that, and your game is ready to play!

# Modifying the Engine
Multiple header and objects exist for the engine. The `AsciiEngine/Engine.h` file is the main engine file to look at. This is a good place to start. All project files are (hopefully) commented well and should give an understanding for each file's purpose. The `AsciiEngine/read_file.cpp` is the main driver file for the engine, which reads in an outside game file and builds that file into a game.