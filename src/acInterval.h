/*
 * Copyright (c) 2017 by Acácio Neimar de Oliveira <neimar2009@gmail.com>
 * acInterval.h library.
 */

#pragma once

class acIntervalClass {
public:
	acIntervalClass(unsigned long timeInterval) : timeInterval(timeInterval) {};
	~acIntervalClass() {};
	// void begin(unsigned long timeInterval, unsigned long timeInit = 0);
	void begin(unsigned long timeInit = 0);
	bool dispatch();
	bool stepHigh();
	unsigned long stepCount();
	void stepCount(unsigned long count);
	unsigned long interval();
	void pause();
	void restart();
	void reset(unsigned long timeInterval = 0);
	unsigned long priorProcess();
	unsigned long nextProcess();
protected:
private:
	bool paused = true;
	unsigned long timeInterval = 0;
	unsigned long timeNow      = 0;
	unsigned long lastTime     = 0;
	unsigned long vStepCount   = 0;
	unsigned long vStepCountLimit = 0xFFFFFFFE;
	uint8_t vStepHigh = 0;
};