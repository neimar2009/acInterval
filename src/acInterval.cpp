/*
 * Copyright (c) 2017 by Acácio Neimar de Oliveira <neimar2009@gmail.com>
 * acInterval.cpp library.
 */

#include <Arduino.h>
#include "acInterval.h"

// timeInterval: Interválo de execução;
// timeInit: Momento de início, em milisegundos, após o inicio do sistema.
void acIntervalClass::begin(unsigned long timeInit = 0) {

  this->startTime = timeInit;
  // this->nextDispatch = millis();
  // if (timeInit == 0) {
  //   timeInit = random(this->timeInterval);
  // }
  this->nextDispatch = millis() + startTime;
  paused = false;
}

// Retorna: true, quando o intervalo estiver completo.
bool acIntervalClass::dispatch() {

  timeNow = millis();
  if(timeNow >= nextDispatch) {
    if (timeNow - nextDispatch >= timeInterval) {
      while(timeNow - nextDispatch >= timeInterval) nextDispatch += timeInterval;
      // Quando pausado, primeiro atualiza 'nextDispatch' para então retornar 'false'.
      if (paused) return false;
      vStepHigh++;
      vStepCount++;
      if (vStepCount == cCountLimit) stepCount(1);
      return true;
    } 
  } else {
    // Resolve o problema quando a contagem chega ao limite e retorna ao zero.
    if (nextDispatch > cCountLimit - timeInterval && nextDispatch - timeNow > startTime){
      nextDispatch += timeInterval;
    }
  }
  return false;
}

// Intervalo par ou impar.
bool acIntervalClass::stepHigh() {
  return (vStepHigh & 1);
}

void acIntervalClass::stepCount(unsigned long count) {
  
  vStepCount = count;
}

//
unsigned long acIntervalClass::stepCount() {

  return vStepCount;
}

// Retorna: o tempo de intervalo em milisegundos.
unsigned long acIntervalClass::interval() {
  return timeInterval;
}

// Apenas altera o valor do intervalo, sem reinício.
void acIntervalClass::interval(unsigned long timeInterval) {

  this->timeInterval = timeInterval;
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
    while(timeNow <= (nextDispatch - timeInterval)) nextDispatch += timeInterval;
  }
  paused = false;
}

// Reinicia o processo como ou sem um novo intervalo de tempo.
void acIntervalClass::reset(unsigned long timeInterval = 0) {
  
  if (timeInterval != 0) this->timeInterval = timeInterval;
  this->nextDispatch = millis();
}

// Retorna o tempo do processo anterior.
unsigned long acIntervalClass::priorProcess() {
  return nextDispatch - timeInterval;
}

// Retorna o tempo para o próximo proceso.
unsigned long acIntervalClass::nextProcess() {
  if(paused) {
    restart();
    pause();
  }
  return nextDispatch;
}
