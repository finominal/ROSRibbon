// Code by JeeLabs http://news.jeelabs.org/code/
// Released to the public domain! Enjoy!

#include <avr/pgmspace.h>
#include "ROSRibbon.h"


#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

Ribbon::Ribbon ()
{
	currentDisplay = -1;
}

Ribbon::Ribbon (int countItems)
{
   length = countItems;
   lastClockRead = 0;
   lastDataRead = 0;
   readSensorCycle = 0;
   lastDetectedTime = 0;
   waitingForClockLow = false;
   
   currentDisplay = -1; //char is used as spaces are present.
   rawSensorData = 0;
   pwmDuty = 0; //the current duty cycle, 0 = off, quarter power 1,2,3 or 4
   
   targetDisplay = countItems;//set to max so the blank section is showing.
   //for(int i = 0; i<countItems;i++} data[i] = -1;
};

void Ribbon::ResetSensorReadCycle()
{
	lastClockRead =0;
	lastDataRead = 0;
	readSensorCycle = 0;
	rawSensorData = 0;
	waitingForClockLow = false;
};


/*
Pass in something to modify
char* Display::toString(char* buf, int maxlen)  
{
 snprintf(buf,maxlen," %02u %02u:%02u:%02u",
             day,
             hour,
             minute,
             second
            );
    return buf;
}
*/