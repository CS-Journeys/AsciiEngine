/*
 * Keyboard.h
 * 
 * Contains necessary functions for unbuffered key input
 * 
 * Note: currently the keyboard only supports 
 *       windows and linux keyboard events
*/

#ifndef KEYBOARD_H
#define KEYBOARD_H

#ifdef _WIN32
#include <windows.h>
#elif __unix__
#include "LinuxTerminal.h"
#elif __APPLE__
#error Coming Soon
#else
#error OS not supported
#endif

#include <map>

class Keyboard {
    private:
        #ifdef __unix__
        Terminal linuxTerminal;
        #endif

        map<char, bool> keys;
   
        //Initializes a map of all alphabetic keyboard keys
        //More keys need to be mapped (such as digits, punctuation, etc)
        void initKeys() {
            for (int i = 41; i < 61; i++) {
                keys.insert(pair<char, bool>((char) i, false));
            }
         }

        //getKey
        //Gets a single key input using unbufferd input
        char getKey(char& key) {
            //TODO: convert standard UNIX keys to Windows Virtual-Key Codes
            #ifdef __unix__
            key = linuxTerminal.getChar();
            #elif _WIN32
            getAsyncKeyState(key);
            #endif
            return key;
        }

    public:
        //Default constructor
        Keyboard() {
            initKeys();
        }

        //keyDown
        //Returns true if key is held down
        bool keyDown(char key) {
            bool down = false;

            if (getKey(key) < 0) {
                down = true;

                keys[key] = true;
            } else {
                keys[key] = false;
            }

            return down;
        }

        //keyUp
        //Returns true if key is not held down
        bool keyUp(char key) {
            bool up = false;
            
            if (getKey(key) >= 0) {
                up = true;

                keys[key] = false;
            } else {
                keys[key] = true;
            }

            return up;
        }

        //keyPress
        //Returns true when key is pressed (and not held down)
        bool keyPress(char key) {
            bool pressed = false;

            if (getKey(key) < 0 && !keys[key]) {
                pressed = true;

                keys[key] = true;
            } else {
                keyUp(key);
            }

            return pressed;
        }

        //keyPress function needed
        //This function does only 1 thing each time the key is pressed
        //Key must be released and then pressed again to do thing again
};

#endif
