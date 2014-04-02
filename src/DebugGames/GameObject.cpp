#include "GameObject.h"

GameObject::GameObject(int x, int y, int sprite = 0) : GObject(x*GE_GLOBAL_TILESIZE,y*GE_GLOBAL_TILESIZE,0,0,true)
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

GameObject::~GameObject()
{

}

