/*

  KITT - An interactive LED chase effect similar to that used on the car
         KITT in Knight Rider TV series, the piezo buzzer is playing the
         soundtrack theme
         
  Copyright (C) 2011 Stefano Cotta Ramusino
  
  Based on Interactive LED Chase Effect project described by Mike
  McRoberts on the Earthshine Design Arduino Starter Kit Manual
  ( http://www.earthshineelectronics.com/files/ASKManualRev5.pdf )

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see < http://www.gnu.org/licenses/ >.
  
*/

#include <Playtune.h>  // a background polyphonic music generator for Aduino
                       // microprocessor boards 
                       // ( http://code.google.com/p/arduino-playtune )
                       
#include "song.h"      // playtune bytestream of Knight Rider theme created
                       // by MIDITONES - http://code.google.com/p/miditones

/* 
  Constants
*/
const byte potPin = 2;             // pin number for the potentiometer
const byte piezoPin = 9;           // pin number for the piezo buzzer
const byte ledPins[] = {3, 4, 5};  // pins number for the LEDs

/* 
  Variables
*/
int ledDelay = 0;          // delay in milliseconds in LED animation
int ledDirection = 1;      // direction of LED animation 
int currentLed = 0;        // current LED number to light
unsigned long changeTime;  // time when last LED has changed state
Playtune pt;               // playtune object used to play song

/*
  Setup function
*/
void setup()
{
  
  pt.tune_initchan(piezoPin);  // set default output for playtune
  
  // set all digital pins used for LEDs in output mode
  for (int i=0; i<sizeof(ledPins); i++)
    pinMode(ledPins[i], OUTPUT);
    
  changeTime = millis();  // set the start time
  
}

/* 
  Loop function
*/
void loop() 
{
  
  // if no song is running start playing the song
  if (!pt.tune_playing)
    pt.tune_playscore(score);
  
  ledDelay = analogRead(potPin);  // get new animation delay from
                                  // the potentiometer
  
  // when the delay is finished proceed to next step of animation
  if ((millis() - changeTime) > ledDelay)
    changeLed();
    
}

/*
  Lights the following LED in the sequence
*/
void changeLed() 
{
  
  // turn off all LEDs except the next one in the animation
  for (int i=0; i<sizeof(ledPins); i++)
    digitalWrite(ledPins[i], (i==currentLed) ? HIGH : LOW);
  
  currentLed += ledDirection;  // set next LED to light
  
  // calculate the new direction
  if (currentLed == sizeof(ledPins)-1)
    ledDirection = -1;
  else if (currentLed == 0)
    ledDirection = 1; 
  
  changeTime = millis();  // set the time when last LED changed

}
