/*
 * Copyright (c) 2017 by Acácio Neimar de Oliveira <neimar2009@gmail.com>
 * acInterval.cpp library.
 */

#include <Arduino.h>
#include "acInterval.h"

void acIntervalClass::begin(unsigned long timeInterval) {

  this->timeInterval = timeInterval; 
}

bool acIntervalClass::dispatch() {

  if (paused) return false;
  unsigned long timeNow = millis();
  if(timeNow >= timeCount){
    if ((timeNow - timeCount >= timeInterval)) {
      timeCount += timeInterval;
      return true;
    } 
  } else {
    if (timeCount > timeInterval)
      while( timeNow - timeCount >= timeInterval) timeCount += timeInterval;
  }
  return false;
}

unsigned long acIntervalClass::interval() {
  return timeInterval;
}

void acIntervalClass::pause() {
  paused = true;
}

void acIntervalClass::restart() {
  
  for (int i = 0; i < 2; ++i) {
    unsigned long timeNow = millis();
    while(timeNow >= timeCount) timeCount += timeInterval;
  }
  paused = false;
}

void acIntervalClass::reset(unsigned long timeInterval = 0) {
  
  if (timeInterval != 0) this->timeInterval = timeInterval;
  timeCount = millis() + timeInterval;
}

unsigned long acIntervalClass::priorProcess() {
  return timeCount - timeInterval;
}

unsigned long acIntervalClass::nextProcess() {
  if(paused) {
    restart();
    pause();
  }
  return timeCount;
}


