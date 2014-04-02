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
#include <vector>


using namespace std;

class GETimer
{
private:
	long currentTime;
	long oldTime;
    float deltaTime;
	 long long passedTime;
	 int passedFrames;
    vector<float> list;
public:
	GETimer();

	virtual ~GETimer();

    float getDeltaTime();

	long getPassedTime();

	long getTotalTime();

	long getSecondTime();

	void Update();

    float getMedia();
};

#endif /* TIMER_H_ */
