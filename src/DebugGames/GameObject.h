#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Graphics/GObject.h"
#include "../Graphics/GETileMap.h"

class GameObject : public GObject
{
private:
    bool talkable;
    bool movable;
    string phrase;
    unsigned char tileType;
    static GETileMap *tilesDoMapa;
    static GETileMap *spritesNpc;
public:
    int Y;
    int X;
    GameObject(int x, int y, unsigned char i, int sprite);
    GameObject(int x, int y, unsigned char i, int sprite, string s);
    string getPhrase();
    bool isTalkable();
    void Draw();
    virtual ~GameObject();
};

#endif // GAMEOBJECT_H
