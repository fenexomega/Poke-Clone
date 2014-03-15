#ifndef FINALGAME_H
#define FINALGAME_H

#include "SDL.h"
#include "../GEGame.h"
#include <vector>
#include "../Graphics/GObject.h"
#include "../Graphics/GELoadingAnimation.h"
#include "../Graphics/GETileMap.h"

class FinalGame : public GEGame
{
private:
    GELoadingAnimation anima;
    int i;
    int time;
    int ymov, xmov;
    GETileMap * background;
    vector<GObject *> objects;
    bool isMoving;
public:
    FinalGame();
    ~FinalGame();

    void gameInit();
    void gameRun();
    void gameUpdate(long currentTime);
    void gameDraw();
    void gameDispose();
};

#endif // FINALGAME_H
