#ifndef RANDTEST_H
#define RANDTEST_H

#include "../GEGame.h"
#include "../GERandom.h"
#include "../GETimer.h"

extern float totalTime;

class RandTest : public GEGame
{
public:
    RandTest();
    void gameUpdate(long currentTime);
    void gameDraw();
	void gameDispose();
};

#endif // RANDTEST_H
