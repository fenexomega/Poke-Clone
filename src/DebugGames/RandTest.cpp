#include "RandTest.h"

RandTest::RandTest()
{
    
}

void RandTest::gameUpdate(long currentTime)
{
    if(GERandom::byChance(60))
        GE_LOG("DEU CERTO  | " << totalTime);
}

void RandTest::gameDraw()
{
    
}

void RandTest::gameDispose()
{
    
}
