#ifndef FONTTEST_H
#define FONTTEST_H
#include "../GEGame.h"
#include "font.h"

class FontTest : public GEGame
{
private:
    Font *font;
    bool aux;
public:
    FontTest();
    virtual ~FontTest();
    void gameInit();
    void gameRun();
    void gameUpdate(long currentTime);
    void gameDraw();
    void gameDispose();
};

#endif // FONTTEST_H
