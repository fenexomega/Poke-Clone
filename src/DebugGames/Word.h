#ifndef WORD_H
#define WORD_H

#include <iostream>
#include "../GEGlobal.h"
#include "font.h"
#include "../Graphics/GEBackground.h"

using namespace std;

class Word
{
private:
    Font *font;
    string phrase;
    string s;
    int x;
    int y;
      int limit;
    bool animated;
    bool active;
     int i;
    float timeAux;
    GEBackground *background;
public:
    Word(string s, int x, int y, int limit,Font *font);
    Word(int x, int y, int limit);
    bool WriteInDelay();
    void Write();
    void Begin(string s);
    bool Continue();
    void Draw();
    bool isActive();
    virtual ~Word();
};

#endif // WORD_H
