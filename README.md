# POVDisplay2

Code for my second persistence of vision display built from scratch. 

Features
* There are now 31 LEDs spanning from center to edge, creating a fully filled-in circular display area. 
* Since that's a lot of LEDs, four daisy-chained shift registers are used to drive each one individually. 
* I ran some basic custom-made benchmark tests to see what microcontroller would be best for driving the shift registers in order to update all of the LEDs 720 times per revolution (very speedy requirement!). I ended up going with the ESP32 Dev Module which has a top CPU frequency of 240MHz (an Arduino Nano is only 2MHz). It also has Wi-Fi and Bluetooth capabilities which will allow for some fancy expansions in the future. 

Functions called in "draw()" determine what will be displayed. The two rectangle functions work fine, but the one for drawing lines is currently unfinished. 
