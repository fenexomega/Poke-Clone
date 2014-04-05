#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../../Graphics/GObject.h"
#include "../../Graphics/GESpriteSheet.h"
#include "../../GEPhysics.h"
#include "../../Graphics/Square.h"
class GameObject : public GObject
{
private:
    bool talkable;
    bool movable;
    string phrase;
    bool visible;
    int tileNumber;
    static GESpriteSheet *spritesNpc;
    int backgroundX;
    int backgroundY;
public:
    int Y;
    int X;
    GameObject(int x, int y, int sprite);
    GameObject(int x, int y, int sprite, string s);
    bool isViewable(int backgroundX, int backgroundY);
    string getPhrase();
    bool isTalkable();
    void Draw();
    virtual ~GameObject();
};

#endif // GAMEOBJECT_H
