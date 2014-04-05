#include "GameObject.h"

GameObject::GameObject(int x, int y, int sprite) : GObject(x*GE_GLOBAL_TILESIZE,y*GE_GLOBAL_TILESIZE,0,0,true)
{
    this->talkable = false;
    this->X = x;
    this->Y = y;
    this->visible = false;
    if(sprite != 0)
    {
        this->visible = true;
        this->tileNumber = sprite;
    }
}



GameObject::GameObject(int x, int y, int sprite, string s) : GObject(x*GE_GLOBAL_TILESIZE,y*GE_GLOBAL_TILESIZE,0,0,true)
{
    this->phrase = s;
    this->talkable = true;
    this->X = x;
    this->Y = y;
    this->backgroundX = backgroundX;
    this->backgroundY = backgroundY;
}

void GameObject::Draw()
{

}

string GameObject::getPhrase()
{
    return phrase;
}

bool GameObject::isTalkable()
{
   return talkable;
}

bool GameObject::isViewable(int backgroundX,int backgroundY)
{
    int x = -backgroundX/GE_GLOBAL_TILESIZE;
    int y = -backgroundY/GE_GLOBAL_TILESIZE;
    int limitY = GE_GLOBAL_SCREEN_HEIGHT/GE_GLOBAL_TILESIZE - 1;
    int limitX = GE_GLOBAL_SCREEN_WIDTH/GE_GLOBAL_TILESIZE  - 1;
    
    Square aux(x*GE_GLOBAL_TILESIZE,y*GE_GLOBAL_TILESIZE
               ,limitX*GE_GLOBAL_TILESIZE,limitY*GE_GLOBAL_TILESIZE);
    
    return GEPhysics::isColliding(this,&aux);
        
}

GameObject::~GameObject()
{

}

