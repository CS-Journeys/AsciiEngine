/*
 * Screen.h
 * 
 * Class for drawing game window
*/

#ifndef SCREEN_H
#define SCREEN_H

#include "GameObject.h"

#include <iostream>
#include <string>

using namespace std;

class Screen {
    private:
        string gameScreen = ""; //The "game window"
        string oldScreen = "";

        //Game window initializer
        void initScreen() {
            gameScreen = "";
            for (int h = 0; h < SCREEN_HEIGHT; h++) {
                for (int w = 0; w < SCREEN_WIDTH; w++) {
                    gameScreen += GAME_BACKGROUND;
                }

                gameScreen += '\n';
            }
        }

        //Clears the window so it can update
        void clearScreen() {
            //Note: Using system() is bad practice and
            //      should be changed later
            if (system(NULL)) {
                system("cls");
            }
        }

        //Draw GameObject sprite with multiple characters
        void drawSprite(int pos, string s) {
            int j = 0, i = 0;

            while (pos < gameScreen.size() && i < s.size()) {
                if (gameScreen[pos] != '\n') {
                    //Add character to screen string
                    if (s[i] != '\n') {
                        //Replace whitespace in sprite
                        if (s[i] == ' ') {
                            gameScreen[pos] = GAME_BACKGROUND;
                        } else {
                            gameScreen[pos] = s[i];
                        }
                    } else {
                        //Go to new line if newline character in sprite
                        pos += SCREEN_WIDTH - j;
                        j = -1;
                    }
                }

                //Increment screen/sprite position
                pos++;
                i++;
                j++;
            }

            return;
        }
    public:
        int SCREEN_WIDTH = 10; //Window width (default value of 10)
        int SCREEN_HEIGHT = 5; //Window height (default value of 5)

        char GAME_BACKGROUND = '.'; //Window background

        bool done = false; //Execution bool

        //Outputs the screen data string
        void drawScreen(ostream& out) {
            if (oldScreen != gameScreen) {
                clearScreen();

                out << gameScreen; 
                oldScreen = gameScreen;
            }
        }

        //Plots an object onto the screen data string
        void spawnObj(GameObject& obj) {
            int pos = 0;
            
            //Iterate through screen height (rows)
            for (int h = 0; h < SCREEN_HEIGHT; h++) {
                //Iterate through screen width (columns)
                for (int w = 0; w < SCREEN_WIDTH; w++) {
                    //Check object position is reached
                    if (w == obj.x && h == obj.y)  {
                        if (obj.sprite.size() > 1) {
                            drawSprite(pos, obj.sprite);
                        } else {
                            //Plot 1 character if sprite size is less than 2
                            gameScreen[pos] = obj.sprite[0];
                        }

                        //End execution once object has been plotted
                        return;
                    }

                    pos++;
                }

                pos++;
            }
        }

        //Quit game
        void quit() {
            done = true;
        }
};

#endif