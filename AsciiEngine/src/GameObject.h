/*
 * GameObject.h
 * 
 * GameObject struct for objects within the game
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

struct GameObject {
    int x = 0, y = 0; //GameObject position
    char pt = 'X'; //GameObject character

    //GameObject collision function
    //Returns true if two objects have the same position
    bool collision(GameObject other) {
        if (this->x == other.x && this->y == other.y) {
            return true;
        }

        return false;
    }
};

#endif