#include "Player.h"


#define PLAYER_GO_DOWN 2
#define PLAYER_GO_UP 11
#define PLAYER_GO_RIGHT 8
#define PLAYER_GO_LEFT 5

Player::Player(int x, int y) : GObject(GE_GLOBAL_TILESIZE *4 ,GE_GLOBAL_TILESIZE * 4 - 16 ,GE_GLOBAL_TILESIZE,GE_GLOBAL_TILESIZE,true)
{
    spriteNbr = 2;
    spritesheet = new GESpriteSheet(GE_GLOBAL_PLAYER_TILEMAP,GE_GLOBAL_TILESIZE);
    this->X = -x/GE_GLOBAL_TILESIZE + 4;
    this->Y = -y/GE_GLOBAL_TILESIZE + 4;

}

Player::~Player()
{

}

void Player::Update(int i,bool moving, int x, int y)
{
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
    this->X = -x/GE_GLOBAL_TILESIZE + 4;
    this->Y = -y/GE_GLOBAL_TILESIZE + 4;

}

void Player::Draw()
{
    GEGraphicsCore::drawSurface_Pos(getX(),getY(),spritesheet->getSprite(),screen,spritesheet->getRect(spriteNbr));
}
