/*
 * Copyright (c) 2017 by Acácio Neimar de Oliveira <neimar2009@gmail.com>
 * acInterval.cpp library.
 */

#include <Arduino.h>
#include "acInterval.h"

// timeIniterval: Interválo de execução;
// timeInit: Momento de início, em milisegundos, após o inicio do sistema.
void acIntervalClass::begin(unsigned long timeInterval, unsigned long timeInit = 0) {

  this->timeInterval = timeInterval;
  this->timeCount = millis();
  if (timeInit == 0) {
    timeInit = random(timeInterval);
  }
  this->timeCount += timeInit;
}

// Retorna: true, quando o intervalo estiver completo.
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

// Retorna: o tempo de intervalo em milisegundos.
unsigned long acIntervalClass::interval() {
  return timeInterval;
}

// Pausa o processo.
void acIntervalClass::pause() {
  paused = true;
}

// Reinicia o processo sincronizado como o momento inicial pré definido.
void acIntervalClass::restart() {
  
  for (int i = 0; i < 2; ++i) {
    unsigned long timeNow = millis();
    while(timeNow >= timeCount) timeCount += timeInterval;
  }
  paused = false;
}

// Reinicia o processo como um novo momento inicial
void acIntervalClass::reset(unsigned long timeInterval = 0) {
  
  if (timeInterval != 0) this->timeInterval = timeInterval;
  timeCount = millis() + timeInterval;
}

// Retorna o tempo do processo anterior.
unsigned long acIntervalClass::priorProcess() {
  return timeCount - timeInterval;
}

// Retorna o tempo para o próximo proceso.
unsigned long acIntervalClass::nextProcess() {
  if(paused) {
    restart();
    pause();
  }
  return timeCount;
}


