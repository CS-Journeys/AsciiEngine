/**
 * linuxterminal-driver.cpp
 *
 * Test driver for LinuxTerminal.h
 */
#include <iostream>
#include "../src/LinuxTerminal.h"

using namespace std;

int main() {
    bool echo = false;
    Terminal terminal(echo);
    char ch;

    //Instructions
    cout << "Press q to quit." << endl;
    cout << "Press e to enable echo." << endl;
    cout << "Press r to remove echo." << endl;

    do {
        //Prompt
        cout << endl << "Please press a key";
        if (echo) {
            cout << ": ";
        } else {
            cout << "..." << endl;
        }

        //Input
        ch = terminal.getChar();

        //Output
        if (echo) {
            cout << endl;
        }
        cout << "You pressed: " << ch << " (" << (int) ch << ")" << endl;

        //Update echo mode
        if (ch == 'e') {
            echo = true;
            terminal.setEcho(echo);
            cout << "Echo enabled." << endl;
        } else if (ch == 'r') {
            echo = false;
            terminal.setEcho(echo);
            cout << "Echo disabled." << endl;
        }
    } while (ch != 'q');

    return 0;
}
