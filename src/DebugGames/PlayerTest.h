/*
 * PlayerTest.h
 *
 *  Created on: 24/02/2014
 *      Author: jordy
 */

#ifndef PlayerTest_H_
#define PlayerTest_H_
#include "../GEGame.h"
#include "../Graphics/GETileMap.h"
#include "../Graphics/GELoadingAnimation.h"
#include <vector>
#include "Player.h"
using namespace std;

class PlayerTest: public GEGame {
private:
    GELoadingAnimation anima;
    int i;
    int k;
    int time;
    int ymov, xmov;
    GETileMap * background;
    vector<GObject *> objects;
    bool isMoving;
    Player *player;
    float timeAux;
    float movingTimeAcc;
    float stepTimeAux;
public:
    PlayerTest();
    ~PlayerTest();
    void gameInit();
    void gameRun();
    void gameUpdate(long currentTime);
    void gameDraw();
    void gameDispose();
};

#endif /* PlayerTest_H_ */
