/*
 * Screen.h
 * 
 * Class for drawing game window
*/

#ifndef SCREEN_H
#define SCREEN_H

#include "GameObject.h"

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class Screen {
    private:
        string gameScreen = ""; //The "game window"
        string oldScreen = "";

        //Checks that a position is within the screen boundaries
        bool withinBoundaries(int x, int y) {
            return x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT;
        }

        //Draw GameObject sprite with multiple characters
        void drawSprite(int pos, GameObject& obj) {
            int j = 0, i = 0;
            int spriteX, spriteY = obj.y;

            while (pos < gameScreen.size() && i < obj.sprite.size()) {
                spriteX = j + obj.x;

                if (gameScreen[pos] != '\n') {
                    //Add character to screen string
                    if (obj.sprite[i] != '\n') {
                        //Check sprite character is within screen
                        if (withinBoundaries(spriteX, spriteY)) {
                            //Replace whitespace in sprite with background
                            if (obj.sprite[i] == ' ') {
                                gameScreen[pos] = GAME_BACKGROUND;
                            } else { //Draw regular character to screen
                                gameScreen[pos] = obj.sprite[i];
                            }
                        }
                    } else {
                        //Go to new line if newline character in sprite
                        pos += SCREEN_WIDTH - j;
                        j = -1;
                        spriteY++;
                    }
                }

                //Increment screen/sprite position
                pos++;
                i++;
                j++;
            }

            return;
        }

        //Sets cursor position in console window
        void setCursorPosition(ostream& out, int x, int y) {
            static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            out.flush();

            COORD position = { (SHORT) x, (SHORT) y };
            //Set cursor position
            SetConsoleCursorPosition(hOut, position);
        }

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
        
        //Outputs the screen data string
        void drawScreen(ostream& out) {
            int pos = 0;

            //Initialize oldScreen on first frame
            if (oldScreen == "") {
                out << gameScreen;
                oldScreen = gameScreen;
                return;
            }

            for (int h = 0; h < SCREEN_HEIGHT; h++) {
                for (int w = 0; w < SCREEN_WIDTH; w++) {
                    //Update screen at changed character positions
                    if (oldScreen[pos] != gameScreen[pos]) {
                        //Set cursor to changed positions and
                         //write to screen at changed positions
                        setCursorPosition(out, w, h);
                        out << gameScreen[pos];
                        oldScreen[pos] = gameScreen[pos];
                    }

                    pos++;
                }

                pos++;
            }

            //Reset cursor position
            setCursorPosition(out, SCREEN_WIDTH + 1, SCREEN_HEIGHT + 1);
        }

        //Plots an object onto the screen
        void spawnObj(GameObject& obj) {
            //Get position in gameScreen
            int pos = SCREEN_WIDTH * obj.y;
            pos += obj.y + obj.x;
            
            if (obj.sprite.size() > 1) {
                drawSprite(pos, obj);
            } else if (obj.sprite.size() > 0) {
                gameScreen[pos] = obj.sprite[0];
            }
            return;
        }

        //Quit game
        void quit() {
            done = true;
        }
};

#endif