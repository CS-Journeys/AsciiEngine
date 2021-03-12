/*
 * Time.h
 * 
 * Time class for getting the execution time
*/

#ifndef TIME_H
#define TIME_H

#include <ctime>

class Time {
    private:
        int startTime;
        int currTime;
    public:
        Time() {
            startTime = clock();
        }

        //Returns the time (milli-seconds) since the last frame
        double getTime() {
            currTime = clock() - startTime;
            startTime = clock(); //Reset startTime for next frame

            return currTime;
        }
};

#endif