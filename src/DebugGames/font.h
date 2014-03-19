#ifndef FONT_H
#define FONT_H

#include "../Graphics/GObject.h"
#include "../Graphics/GESpriteSheet.h"
#include <vector>

using namespace std;

class Font
{
private:
    int iaux;
    bool showing;
    GESpriteSheet *letters;
    float timeAux;
public:
    Font();
    virtual ~Font();
    int GetLetterNumber(char c);
    void WriteString(string s,int x,int y,int coef);
    void WriteChar(char c,int x, int y);
};

#endif // FONT_H
