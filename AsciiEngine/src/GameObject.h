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
};

#endif