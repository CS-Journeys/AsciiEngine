/*
 * Keyboard.h
 * 
 * Contains necessary functions for unbuffered key input
 * 
 * Note: currently the keyboard only supports 
 *       windows keyboard events
*/

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <windows.h>
#include <map>

class Keyboard {
    private:
        map<char, bool> keys;
        
        //Initializes a map of all alphabetic keyboard keys
        //More keys need to be mapped (such as digits, punctuation, etc)
        void Init_Keys() {
            for (int i = 41; i < 61; i++) {
                keys.insert(pair<char, bool>((char) i, false));
            }
        }
    public:
        //Default constructor
        Keyboard() {
            Init_Keys();
        }

        //keyDown
        //Returns true if key is held down
        bool keyDown(char key) {
            bool down = false;

            if (GetAsyncKeyState(key) < 0) {
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
            
            if (GetAsyncKeyState(key) >= 0) {
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

            if (GetAsyncKeyState(key) < 0 && !keys[key]) {
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