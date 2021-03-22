/*
 * GameObject.h
 * 
 * GameObject struct for objects within the game
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <fstream>

using namespace std;

struct GameObject {
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
        //Read sprite file to certain line or end of file
        while (spriteFile.get(c) && !done) {
            sprite += c;

            if (lastLine >= 0 && i == lastLine) {
                done = true;
            }

            if (c == '\n') {
                i++;
            }
        }

        spriteFile.close();
    }
};

#endif