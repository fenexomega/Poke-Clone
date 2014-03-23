#ifndef GEPLAYER_H
#define GEPLAYER_H

#include "../Graphics/GObject.h"
#include "../Graphics/GESpriteSheet.h"
#include "GameObject.h"
#include "GlobalSettings.h"

class Player : public GObject
{
private:
    int auxX,auxY;
    GESpriteSheet *spritesheet;
    unsigned char spriteNbr;
    unsigned char orientation;
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
