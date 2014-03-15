#ifndef GESPRITEANIMATION_H
#define GESPRITEANIMATION_H

#include "GESpriteSheet.h"

class GESpriteAnimation
{
private:
    GESpriteSheet *spritesheet;
public:
    GESpriteAnimation(string imagename,int sprite_size);
    GESpriteAnimation(GESpriteSheet *spritesheet);
};

#endif // GESPRITEANIMATION_H
