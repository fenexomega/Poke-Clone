#ifndef WORD_H
#define WORD_H

#include <iostream>
#include "../GEGlobal.h"
#include "font.h"

using namespace std;

class Word
{
private:
    Font *font;
    string s;
    int x;
    int y;
    int limit;
    bool showing;
    int i;
    float timeAux;
public:
    Word(string s, int x, int y, int limit,Font *font);
    bool WriteInDelay();
    void Write();
    void setString(string s);
};

#endif // WORD_H
