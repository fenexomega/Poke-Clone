#include "GESpriteAnimation.h"

GESpriteAnimation::GESpriteAnimation(string imagename,int sprite_size)
{
    spritesheet = new GESpriteSheet(imagename,sprite_size,1);

}
