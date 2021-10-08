#include "Display.h"

uint8_t Display::grid[360 * DENSITY][NUMLEDS];

uint8_t Display::getState(uint16_t angle, uint8_t radius) {
  return grid[angle][radius];
}

void Display::clear() {
  for (uint16_t a = 0; a < 360 * DENSITY; a++)
    for (uint8_t r = 0; r < NUMLEDS; r++)
      grid[a][r] = 0;
}

void Display::addPoint(int8_t x, int8_t y) {
  uint16_t angle = degrees(atan2(y, x)) + (y < 0 ? 360 : 0);
  uint8_t radius = sqrt(pow(x, 2) + pow(y, 2)) / DENSITY;
  if (radius < NUMLEDS)
    grid[angle * DENSITY][radius] = 1;
}

void Display::fillRect(int8_t rectX, int8_t rectY, uint8_t width, uint8_t height) {
  rectX *= DENSITY;
  rectY *= DENSITY;
  width *= DENSITY;
  height *= DENSITY;
  for (int8_t y = rectY; y < rectY + height; y++)
    for (int8_t x = rectX; x < rectX + width; x++)
      addPoint(x, y);
}

void Display::drawRect(int8_t rectX, int8_t rectY, uint8_t width, uint8_t height, uint8_t thickness) {
  rectX *= DENSITY;
  rectY *= DENSITY;
  width *= DENSITY;
  height *= DENSITY;
  thickness *= DENSITY;
  for (uint8_t t = 0; t < thickness; t++) {
    // right and left sides
    for (int8_t y = rectY; y < rectY + height; y++) {
      addPoint(rectX + t, y);
      addPoint(rectX + width - t, y);
    }
    // top and bottom sides
    for (int8_t x = rectX; x < rectX + width; x++) {
      addPoint(x, rectY + t);
      addPoint(x, rectY + height - t);
    }
  }
}

// TODO: add functionality for other octants
// TODO: add thickness option
// uses Bresenham's Algorithm
void Display::drawLine(int8_t x1, int8_t y1, int8_t x2, int8_t y2) {
  x1 *= DENSITY;
  y1 *= DENSITY;
  x2 *= DENSITY;
  y2 *= DENSITY;
  int8_t dy = y2 - y1;
  int8_t dx = x2 - x1;
  int8_t y = y1;
  int8_t error = dy - dx;
  // check if slope is less than or equal to 1
  if (dy <= dx) {
    // loop through each x value
    for (int8_t x = x1; x < x2; x++) {
      addPoint(x, y);
      // time to go to the next level of pixels
      if (error >= 0) {
        if (dy <= 0)
          // increment y if slope is zero or negative
          y++;
        else
          // decrement y if slope is positive
          y--;
        error -= abs(dx);
      }
      error += abs(dy);
    }
  } else {
    // loop through each y value
    for (int8_t y = y1; y < y2; y++) {

    }
  }
}
