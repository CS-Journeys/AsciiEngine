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
    void readSprite(string path) {
        char c;
        ifstream spriteFile (path.c_str());

        while (spriteFile.get(c)) {
            sprite += c;
        }

        spriteFile.close();
    }
};

#endif