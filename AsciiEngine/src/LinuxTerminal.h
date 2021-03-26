#ifndef LINUXTERMINAL_H
#define LINUXTERMINAL_H

#include <termios.h>

class Terminal {
    private:
        termios oldSettings, currentSettings;
        bool echo;

    public:
        //Constructor
        //Initializes terminal i/o settings with unbuffered input
        Terminal(bool echo = false) {
            tcgetattr(0, &oldSettings); // grab old terminal i/o settings
            currentSettings = oldSettings;
            currentSettings.c_lflag &= ~ICANON; // disable buffered i/o
            setEcho(echo);
        }

        //Destructor
        //Restores old terminal i/o settings
        ~Terminal() {
            tcsetattr(0, TCSANOW, &oldSettings);
        }

        //setEcho
        //Enables or disables echo mode given the parameter's value
        void setEcho(bool echo) {
            this->echo = echo;
            if (echo) {
                currentSettings.c_lflag |= ECHO;
            } else {
                currentSettings.c_lflag &= ~ECHO;
            }
            tcsetattr(0, TCSANOW, &currentSettings);
        }

        //getChar
        //Returns a single character using unbuffered input
        char getChar() {
            return getchar();
        }
};

#endif //LINUXTERMINAL_H

