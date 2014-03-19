#ifndef BATTLETEST_H
#define BATTLETEST_H
#include "../GEGame.h"


class BattleTest : public GEGame
{
public:
    BattleTest();
    virtual ~BattleTest();
    void gameInit();
    void gameRun();
    void gameUpdate(long currentTime);
    void gameDraw();
    void gameDispose();
};

#endif // BATTLETEST_H
