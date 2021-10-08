#include "LEDs.h"

void LEDs::enable() {
  //  digitalWrite(OE, LOW);
  REG_WRITE(GPIO_OUT_REG, 0 << OE);
}

void LEDs::disable() {
  //  PORTD |= 1 << OE;

  //  digitalWrite(OE, HIGH);

  REG_WRITE(GPIO_OUT_REG, 1 << OE);
}

void LEDs::clear() {
  //  PORTD &= ~(1 << SRCLR);
  //  PORTD |= 1 << SRCLR;

  //  digitalWrite(SRCLR, LOW);
  //  digitalWrite(SRCLR, HIGH);

  REG_WRITE(GPIO_OUT1_REG, 0 << SRCLR - 32);		// TODO: this might not be working - hard to tell
  REG_WRITE(GPIO_OUT1_REG, 1 << SRCLR - 32);
}

void LEDs::shiftBit(uint8_t b) {
  //  PORTD |= b << SER;
  //  PORTD |= 1 << SRCLK;
  //  PORTD &= ~(1 << SER | 1 << SRCLK);

  //  digitalWrite(SER, b);
  //  digitalWrite(SRCLK, HIGH);
  //  digitalWrite(SRCLK, LOW);

  REG_WRITE(GPIO_OUT_REG, b << SER);
  //  REG_WRITE(GPIO_OUT_REG, 1 << SRCLK);	// TODO: why does this not work?
  //  REG_WRITE(GPIO_OUT_REG, 0 << SRCLK);
  digitalWrite(SRCLK, HIGH);
  digitalWrite(SRCLK, LOW);
}

void LEDs::show() {
  //  PORTD |= 1 << RCLK;
  //  PORTD &= ~(1 << RCLK);

  //  digitalWrite(RCLK, HIGH);
  //  digitalWrite(RCLK, LOW);

  REG_WRITE(GPIO_OUT_REG, 1 << RCLK);
  REG_WRITE(GPIO_OUT_REG, 0 << RCLK);
}
