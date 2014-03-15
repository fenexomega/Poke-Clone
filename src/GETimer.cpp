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
//	std::cout << "PassedTime: "  <<	oldTime << std::endl;
//	std::cout << "CurrentTime: " << currentTime << std::endl;
//	std::cout << "DeltaTime: " 	 << deltaTime << std::endl;
//	std::cout << "SecondTime: " 	 << currentTime % 1000 << std::endl;
//	std::cout << "Frames: " 	 << passedFrames << std::endl;

}
