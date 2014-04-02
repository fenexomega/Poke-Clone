/*
 * GETimer.cpp
 *
 *  Created on: 25/02/2014
 *      Author: jordy
 */
#include "GETimer.h"

#include <iostream>

GETimer::GETimer()
{
	currentTime = SDL_GetTicks();
	passedFrames = 0;
	passedTime = 0;
}

GETimer::~GETimer()
{

}

long GETimer::getPassedTime()
{
	return deltaTime;
}

long GETimer::getTotalTime()
{
	return currentTime/1000.0f;
}

long GETimer::getSecondTime()
{
	return currentTime % 1000;
}

float GETimer::getDeltaTime()
{
    return deltaTime;
}

void GETimer::Update()
{
	oldTime = currentTime;
	currentTime = SDL_GetTicks();
	deltaTime = (currentTime - oldTime)/1000.0f;
	passedFrames++;

	if(oldTime % 1000 > currentTime % 1000)
	{
		passedFrames = 0;
	}
    list.push_back(deltaTime);
    if(list.size() > 10)
        list.erase(list.begin());
}
float GETimer::getMedia()
{
    float acc = 0;
    for(unsigned int i = 0; i < list.size(); ++i)
    {
        acc += list[i];
    }
    acc /= list.size();
    acc *= 1000;
    return acc ;
}
