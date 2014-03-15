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
    Player();
    virtual ~Player();
    void Update(int i,bool moving);
    void Draw();
};

#endif // GEPLAYER_H
