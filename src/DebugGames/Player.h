#ifndef GEPLAYER_H
#define GEPLAYER_H

#include "../Graphics/GObject.h"
#include "../Graphics/GESpriteSheet.h"

class Player : public GObject
{
private:
    GESpriteSheet *spritesheet;
    unsigned char spriteNbr;
public:
    Player(int x, int y);
    virtual ~Player();
    void Update(int i,bool moving, int x, int y);
    void Draw();
    int X;
    int Y;
};

#endif // GEPLAYER_H
