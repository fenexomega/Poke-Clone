#ifndef DIALOGUETEST_H
#define DIALOGUETEST_H

#include "../GEGame.h"
#include "../Graphics/GETileMap.h"
#include "../Graphics/GELoadingAnimation.h"
#include <vector>
#include "../Game/Game_Classes/Player.h"
#include "../Game/Game_Classes/Word.h"
#include "../Game/Game_Classes/GameObject.h"
using namespace std;

class DialogueTest: public GEGame {
private:
    Word *word;
    GELoadingAnimation anima;
    int i;
    int k;
    int time;
    int ymov, xmov;
    GETileMap * background;
    vector<GameObject *> objects;
    bool isMoving;
    Player *player;
    float timeAux;
    float movingTimeAcc;
    float stepTimeAux;
    bool debug;
	vector<GameObject *> viewbleObjects;
public:
    DialogueTest();
    ~DialogueTest();
    void gameUpdate(long currentTime);
    void gameDraw();
    void gameDispose();
    void SeeIfUserWannaTalk();
    void DrawDebugInfo();
    void UpdatePlayerInputForMoving();
};

#endif // DIALOGUETEST_H
