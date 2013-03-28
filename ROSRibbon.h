// Code by JeeLabs http://news.jeelabs.org/code/
// Released to the public domain! Enjoy!

#ifndef __ROSRibbon_H__
#define __ROSRibbon_H__

class Ribbon
{
  public:
  Ribbon();
  Ribbon(int countItems);
  void ResetSensorReadCycle();
  //char* toString(char* buf, int maxlen);
  
  int length;
  
  int lastClockRead, lastDataRead, thisClockRead, thisDataRead;
  int readSensorCycle;
  char rawSensorData; //write in sensor results a bit at a time
  long lastDetectedTime;
  bool waitingForClockLow;
  
  int targetDisplay;
  int currentDisplay; //spaces have highest value
  int pwmDuty; //the current duty cycle, 0 = off, quarter increments 1,2,3 or 4

};

#endif 