#ifndef GERANDOM_H
#define GERANDOM_H

#include <stdlib.h>
#include <time.h>

class GERandom
{
private:
public:
    GERandom();
    static bool byChance(float percent);
    static void initRandomSeed();
    static int getInt(int num);
};

#endif // GERANDOM_H
