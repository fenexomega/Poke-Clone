#ifndef GEPLAYER_H
#define GEPLAYER_H

#include "GameObject.h"
#include "GlobalSettings.h"
#include "Pokemon.h"

class Player : public GObject
{
private:
    int auxX,auxY;
    GESpriteSheet *spritesheet;
     char spriteNbr;
     char orientation;
    Pokemon pokevector[6];
public:
    Player(int x, int y);
    virtual ~Player();
    void Update(int i,bool moving);
    void UpdatePos(int x, int y);
    void Draw();
    int X;
    int Y;
    bool inFrontOf(GameObject *obj);
};

#endif // GEPLAYER_H
