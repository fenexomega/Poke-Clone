#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Graphics/GObject.h"
#include "../Graphics/GESpriteSheet.h"

class GameObject : public GObject
{
private:
    bool talkable;
    bool movable;
    string phrase;
    bool visible;
    int tileNumber;
    static GESpriteSheet *spritesNpc;
public:
    int Y;
    int X;
    GameObject(int x, int y, int sprite);
    GameObject(int x, int y, int sprite, string s);
    string getPhrase();
    bool isTalkable();
    void Draw();
    virtual ~GameObject();
};

#endif // GAMEOBJECT_H
