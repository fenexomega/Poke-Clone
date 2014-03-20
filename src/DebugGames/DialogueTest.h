#ifndef DIALOGUETEST_H
#define DIALOGUETEST_H

#include "../GEGame.h"
#include "../Graphics/GETileMap.h"
#include "../Graphics/GELoadingAnimation.h"
#include <vector>
#include "Player.h"
using namespace std;

class DialogueTest: public GEGame {
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
    DialogueTest();
    ~DialogueTest();
    void gameInit();
    void gameRun();
    void gameUpdate(long currentTime);
    void gameDraw();
    void gameDispose();
};

#endif // DIALOGUETEST_H
