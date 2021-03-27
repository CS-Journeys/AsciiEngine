/*
 * GameObject.h
 * 
 * GameObject struct for objects within the game
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class GameObject {
    private:
        int sprWidth = 0, sprHeight = 0;
    public:
        int x = 0, y = 0; //GameObject position
        string sprite = ""; //GameObject character

        //GameObject collision function
        //Returns true if two objects have the same position
        bool collision(GameObject other) {
            if (this->x == other.x && this->y == other.y) {
                return true;
            }

            return false;
        }

        //Moves the current gameobject relative to another gameobject plus an offset
        void moveRelativeTo(GameObject& other, int xOff, int yOff) {
            this->x = other.x + xOff;
            this->y = other.y + yOff;
        }

        //Reads an inputted ascii art sprite from user defined file
        void readSprite(string path, int lastLine = -1) {
            char c;
            ifstream spriteFile (path.c_str());
            bool done = false;

            int i = 0;
            int currXSize = 0;
            //Read sprite file to certain line or end of file
            while (spriteFile.get(c) && !done) {
                sprite += c;
                
                //If at least one character is found, height is 1
                if (sprHeight == 0) {
                    sprHeight++;
                }

                if (lastLine >= 0 && i == lastLine) {
                    done = true;
                }

                if (c == '\n') {
                    i++;

                    //Get max width of sprite
                    sprWidth = max(currXSize, sprWidth);
                    currXSize = 0;

                    //Increment height of sprite
                    sprHeight++;
                }

                currXSize++;
            }

            spriteFile.close();
        }

        //Get sprite width
        int getWidth() {
            return sprWidth;
        }

        //Get sprite height
        int getHeight() {
            return sprHeight;
        }
};

#endif