#ifndef LEDs_h
#define LEDs_h

#include "Arduino.h"
#include "Constants.h"

class LEDs {
  public:
    static void enable();
    static void disable();
    static void clear();
    static void shiftBit(uint8_t);
    static void show();
};

#endif
