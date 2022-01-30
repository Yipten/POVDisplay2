# POVDisplay2

## What is it? 

This is the code for the second, more advanced version of my previous [POVDisplay](https://github.com/Yipten/POVDisplay) project. Instead of having five LEDs that display text around the edge of the circle, this version has 31 LEDs that span from the center to the edge, allowing for images to be drawn anywhere within the entire circle. Since the 2MHz clock speed of an Arduino Nano wouldn't be fast enough to handle this, an ESP32 with a 240MHz clock speed was used instead. This board also has Wi-Fi and Bluetooth capabilities, which will allow for the possibility of adding wireless controls in the future. 

<!-- TODO: add GIF image -->

## Hardware

### Wiring

<!-- TODO: explain how shift registers were daisy-chained together -->
Connections to the ESP32 microcontroller: 

| ESP32 pin | Connection         |
| --------- | ------------------ |
| micro USB | battery pack USB   |
| 27        | SR SER             |
| 26        | SR OE              |
| 25        | SR RCLK            |
| 33        | SR SRCLK           |
| 32        | SR SRCLR           |
| 34        | hall effect sensor |

*SR = shift register*

### Assembly

All of the electronic components were soldered together on two solderable PCBs stacked on top of each other. The bottom PCB had the ESP32 and shift registers, and the top one had the LEDs. 

Once all of the hardware was assembled, it looked like this: 

<!-- TODO: add static image -->

## Use

## How does it work? 


<!-- old README text: 
Code for my second persistence of vision display built from scratch. 

Features
* There are now 31 LEDs spanning from center to edge, creating a fully filled-in circular display area. 
* Since that's a lot of LEDs, four daisy-chained shift registers are used to drive each one individually. 
* I ran some basic custom-made benchmark tests to see what microcontroller would be best for driving the shift registers in order to update all of the LEDs 720 times per revolution (very speedy requirement!). I ended up going with the ESP32 Dev Module which has a top CPU frequency of 240MHz (an Arduino Nano is only 2MHz). It also has Wi-Fi and Bluetooth capabilities which will allow for some fancy expansions in the future. 

Functions called in "draw()" determine what will be displayed. The two rectangle functions work fine, but the one for drawing lines is currently unfinished. 
-->