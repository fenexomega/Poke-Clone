#include "GERandom.h"

GERandom::GERandom()
{
}

void GERandom::initRandomSeed()
{
    srand(time(NULL));    
}

bool GERandom::byChance(float percent)
{    
    return (rand()%100 + 1) <= percent;       
}

int GERandom::getInt(int num)
{
    return rand()%num;
}
