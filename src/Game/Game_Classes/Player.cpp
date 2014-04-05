#include "Player.h"

Player::Player(int x, int y) : GObject(GE_GLOBAL_TILESIZE *4 ,GE_GLOBAL_TILESIZE * 4 - 16 ,GE_GLOBAL_TILESIZE,GE_GLOBAL_TILESIZE,true)
{
    spriteNbr = 2;
    spritesheet = new GESpriteSheet(GE_GLOBAL_PLAYER_TILEMAP,GE_GLOBAL_TILESIZE,0);
    this->X = -x/GE_GLOBAL_TILESIZE + 4;
    this->Y = -y/GE_GLOBAL_TILESIZE + 4;

}

Player::~Player()
{

}

void Player::Update(int i,bool moving)
{
    orientation = i;
    if(!moving)
        spriteNbr = i;
    else
    {
        if(i - 1 != spriteNbr && i != spriteNbr && i + 1 != spriteNbr &&  i + 2 != spriteNbr)
            spriteNbr = i;
        if(spriteNbr >= 1 && spriteNbr <= 4)
        {
            ++spriteNbr%=5;
            if(spriteNbr == 0)
                spriteNbr = 1;
        }
        else
        if(spriteNbr >= 5 && spriteNbr <= 8)
        {
            ++spriteNbr%=9;
            if(spriteNbr == 0)
                spriteNbr = 5;
        }
        else
        if(spriteNbr >= 9 && spriteNbr <= 12)
        {
            ++spriteNbr%=13;
            if(spriteNbr == 0)
                spriteNbr = 9;
        }
        else
        if(spriteNbr >= 13 && spriteNbr <= 16)
        {
            ++spriteNbr%=17;
            if(spriteNbr == 0)
                spriteNbr = 13;
        }
    }

}

void Player::UpdatePos(int x, int y)
{
    this->X = -x/GE_GLOBAL_TILESIZE + 4;
    this->Y = -y/GE_GLOBAL_TILESIZE + 4;
}

void Player::Draw()
{
    GEGraphicsCore::drawSurface_Pos(getX(),getY(),spritesheet->getSprite(),screen,spritesheet->getRect(spriteNbr));
}

bool Player::inFrontOf(GameObject *obj)
{
    switch(orientation)
    {
    case PLAYER_GO_DOWN:
        auxX = X;
        auxY = Y + 1; break;
    case PLAYER_GO_UP:
        auxX = X;
        auxY = Y - 1; break;
    case PLAYER_GO_LEFT:
        auxX = X - 1;
        auxY = Y; break;
    case PLAYER_GO_RIGHT:
        auxX = X + 1;
        auxY = Y; break;
    }
    return (obj->X == auxX) && (obj->Y == auxY);
}
