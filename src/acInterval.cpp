/*
 * Copyright (c) 2017 by Acácio Neimar de Oliveira <neimar2009@gmail.com>
 * acInterval.cpp library.
 */

#include <Arduino.h>
#include "acInterval.h"

// timeIniterval: Interválo de execução;
// timeInit: Momento de início, em milisegundos, após o inicio do sistema.
// void acIntervalClass::begin(unsigned long timeInterval, unsigned long timeInit = 0) {
void acIntervalClass::begin(unsigned long timeInit = 0) {

  // this->timeInterval = timeInterval;
  this->lastTime = millis();
  if (timeInit == 0) {
    timeInit = random(this->timeInterval);
  }
  this->lastTime += timeInit;
  paused = false;
}

// Retorna: true, quando o intervalo estiver completo.
bool acIntervalClass::dispatch() {

  unsigned long timeNow = millis();
  if(timeNow >= lastTime) {
    if ((timeNow - lastTime >= timeInterval)) {
      lastTime += timeInterval;
      // Quando pausado, primeiro atualiza 'lastTime' para então retornar 'false'.
      if (paused) return false;
      vStepHigh++;
      vStepCount++;
      if (vStepCount > vStepCountLimit) vStepCount = 1;
      return true;
    } 
  } else {
    // Resolve o problema quando a contagem chega ao limite e retorna ao zero.
    if (lastTime > timeInterval) {
      while((timeNow - lastTime) > timeInterval) lastTime += timeInterval;
    }
  }
  return false;
}

// Intervalo par ou impar.
bool acIntervalClass::stepHigh() {
  return (vStepHigh & 1);
}

void acIntervalClass::stepCount(unsigned long count) {
  
  vStepCountLimit = count;
}

//
unsigned long acIntervalClass::stepCount() {

  return vStepCount;
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
  
  if(timeInterval == 0) return;
  for (uint8_t i = 0; i < 2; ++i) {
    // Resolve o problema quando a contagem chega ao limite e retorna ao zero.
    unsigned long timeNow = millis();
    while(timeNow <= (lastTime - timeInterval)) lastTime += timeInterval;
  }
  paused = false;
}

// Reinicia o processo como um novo momento inicial
void acIntervalClass::reset(unsigned long timeInterval = 0) {
  
  if (timeInterval != 0) this->timeInterval = timeInterval;
  this->lastTime = millis();
}

// Retorna o tempo do processo anterior.
unsigned long acIntervalClass::priorProcess() {
  return lastTime - timeInterval;
}

// Retorna o tempo para o próximo proceso.
unsigned long acIntervalClass::nextProcess() {
  if(paused) {
    restart();
    pause();
  }
  return lastTime;
}
