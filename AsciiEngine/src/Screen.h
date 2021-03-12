/*
 * Screen.h
 * 
 * Class for drawing game window
*/

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

using namespace std;

class Screen {
    private:
        string gameScreen = ""; //The "game window"
    public:
        int SCREEN_WIDTH = 10; //Window width (default value of 10)
        int SCREEN_HEIGHT = 5; //Window height (default value of 5)

        char GAME_BACKGROUND = '.'; //Window background

        bool done = false; //Execution bool

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

        //Outputs the screen data string
        void drawScreen(ostream& out) {
            clearScreen();

            out << gameScreen;
        }

        //Plots an object onto the screen data string
        void spawnObj(int& xPos, int& yPos, char c) {
            int pos = 0;

            //If invalid position, set to inside window
            if (xPos >= SCREEN_WIDTH) {
                xPos = 0;
            } else if (xPos < 0) {
                xPos = SCREEN_WIDTH - 1;
            }

            if (yPos >= SCREEN_HEIGHT) {
                yPos = 0;
            } else if (yPos < 0) {
                yPos = SCREEN_HEIGHT - 1;
            }

            //Plot the object at the position in the screen
            for (int h = 0; h < SCREEN_HEIGHT; h++) {
                for (int w = 0; w < SCREEN_WIDTH; w++) {
                    if (w == xPos && h == yPos)  {
                        gameScreen[pos] = c;
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