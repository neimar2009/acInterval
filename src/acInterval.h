/*
 * Copyright (c) 2017 by Acácio Neimar de Oliveira <neimar2009@gmail.com>
 * acInterval.h library.
 */

#pragma once

class acIntervalClass {
public:
	acIntervalClass() {};
	~acIntervalClass() {};
	void begin(unsigned long timeInterval, unsigned long timeInit = 0);
	bool dispatch();
	bool stepState();
	unsigned long stepCount();
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
	unsigned long initialTime  = 0;
	unsigned long vStepState = 0;
	unsigned long vStepCount = 0;
	unsigned long vStepCountLimit = 0xFFFFFFFF;
};