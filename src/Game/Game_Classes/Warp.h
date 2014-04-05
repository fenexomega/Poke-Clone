#ifndef WARP_H
#define WARP_H

#include "Player.h"

class Warp
{
private:
    int x;
    int y;
    int toX;
    int toY;
public:
    Warp(int x, int y, int toX, int toY,int toZ);
    void teleport(Player &player);
};

#endif // WARP_H
