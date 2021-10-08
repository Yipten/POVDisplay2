#include <WiFi.h>
#include "Constants.h"
#include "Display.h"
#include "LEDs.h"

// flag for breaking out of main loop
volatile uint8_t sensorFlag = false;
// timestamp for determining microseconds per revolution
uint32_t timeStamp = 0;
// microseconds per revolution
uint32_t microsPerRev = 0;

void draw() {
  // clear grid just to be safe
  Display::clear();

  Display::drawLine(-15, -20, 10, 10);
  Display::drawLine(0, 0, 10, 10);
  Display::drawLine(-25, 5, 20, 15);
  //  Display::drawLine(0, 0, 7, 28);
}

void breakLoop() {
  // raises flag causing main loop to end early
  sensorFlag = true;
}

void setup() {
  // turn off radios
  WiFi.mode(WIFI_OFF);
  btStop();
  // set outputs
  pinMode(SER, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(SRCLR, OUTPUT);
  // set inputs
  pinMode(SENSOR, INPUT);
  // set output pins to initial states
  digitalWrite(SER, LOW);
  digitalWrite(OE, LOW);
  digitalWrite(RCLK, LOW);
  digitalWrite(SRCLK, LOW);
  digitalWrite(SRCLR, HIGH);
  // attach interrupt on sensor pin
  attachInterrupt(SENSOR, breakLoop, FALLING);
  // clear shift register just to be safe
  LEDs::clear();
  LEDs::show();
  // draw shapes to be displayed
  draw();
}

void loop() {
  // get elapsed microseconds
  microsPerRev = micros() - timeStamp;
  // get current time in microseconds
  timeStamp = micros();
  // loop through angles
  for (uint16_t a = 0; a < 360 * DENSITY; a++) {
    // end main loop early if flag is raised
    if (sensorFlag) {
      sensorFlag = false;
      return;
    }
    // loop through radii
    for (int8_t r = NUMLEDS - 1; r >= 0; r--)
      // shift in next state
      LEDs::shiftBit(Display::getState(a, r));
    // store data in storage register
    LEDs::show();
    // delay based on microsPerRev
    delayMicroseconds(microsPerRev / (360.0f * DENSITY) - DELAY_OFFSET);
  }
  // loop while waiting for sensor interrupt
  while (!sensorFlag);
  // reset flag for next loop
  sensorFlag = false;
}
