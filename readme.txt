KITT
====

An interactive LED chase effect similar to that used on the car
KITT in Knight Rider TV series, the piezo buzzer is playing the
soundtrack theme.
         
Based on Interactive LED Chase Effect project described by Mike
McRoberts on the Earthshine Design Arduino Starter Kit Manual
(http://www.earthshineelectronics.com/files/ASKManualRev5.pdf).

Make the circuit available on KITT.png and open the KITT.ino
sketch and upload to your Arduino.

Successfully tested on Arduino Uno board with Arduino 1.0-rc1,
as you can see here: http://vimeo.com/31233250.


Playtune
--------

A background polyphonic music generator for Aduino microprocessor
boards used in this sketch, available on:
http://code.google.com/p/arduino-playtune

Small changes to make the library (version Feb 2011) compatible
with Arduino 1.0:

- Playtune.h
  change "WProgram.h" in <Arduino.h>
  
- Playtune.c
  change <wiring.h> in <wiring.c>
  

Stefano Cotta Ramusino <whitone (at) gmail (dot) com>