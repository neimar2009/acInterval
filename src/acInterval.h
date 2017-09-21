/*
 * Copyright (c) 2017 by Acácio Neimar de Oliveira <neimar2009@gmail.com>
 * acInterval.h library.
 */

#pragma once

class acIntervalClass {
public:
	acIntervalClass() {};
	~acIntervalClass() {};
	void begin(unsigned long timeInterval);
	bool dispatch();
	unsigned long interval();
	void pause();
	void restart();
	void reset(unsigned long timeInterval = 0);
	unsigned long priorProcess();
	unsigned long nextProcess();
protected:
private:
	bool paused = false;
	unsigned long timeInterval = 0;
	unsigned long timeCount    = 0;
};