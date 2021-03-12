/*
 * Engine.h
 * 
 * Main AsciiEngine header file
*/

#ifndef ENGINE_H
#define ENGINE_H

#include "src/Screen.h"
#include "src/GameObject.h"
#include "src/Time.h"
#include "src/Keyboard.h"

//External classes used across files
extern Screen Window;
extern Keyboard Input;
extern Time runTime;

//Declaration of onLoad and Update functions
//User will "define" these in their game file
void onLoad();
void Update();

#endif