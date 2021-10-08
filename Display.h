#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include "Constants.h"

// manages data to be displayed
class Display {
  public:
    // returns the desired state of the LED at the given angle and radius
    static uint8_t getState(uint16_t, uint8_t);
    // resets all display data to zero
    static void clear();
    // sets the point to 1 that is the equivalent of the given rectangular coordinates
    static void addPoint(int8_t, int8_t);
    // filled-in rectangle
    static void fillRect(int8_t, int8_t, uint8_t, uint8_t);
    // outlined rectangle
    static void drawRect(int8_t, int8_t, uint8_t, uint8_t, uint8_t);
    // straight line
    static void drawLine(int8_t, int8_t, int8_t, int8_t);

  private:
    // array representing all display data
    static uint8_t grid[360 * DENSITY][NUMLEDS];
};

#endif
