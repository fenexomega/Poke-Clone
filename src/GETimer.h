/*
 * Timer.h
 *
 *  Created on: 12/02/2014
 *      Author: jordy
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <SDL/SDL.h>
#include "GEGlobal.h"

//TODO EVERYTHING

class GETimer
{
private:
	long currentTime;
	long oldTime;
    float deltaTime;
	unsigned long long passedTime;
	unsigned int passedFrames;
public:
	GETimer();

	virtual ~GETimer();

    float getDeltaTime();

	long getPassedTime();

	long getTotalTime();

	long getSecondTime();

	void Update();
};

#endif /* TIMER_H_ */
