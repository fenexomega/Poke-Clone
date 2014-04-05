#ifndef FONTTEST_H
#define FONTTEST_H
#include "../GEGame.h"
#include "../Game/Game_Classes/font.h"
#include "../Game/Game_Classes/Word.h"
#include "../Graphics/GEBackground.h"

class FontTest : public GEGame
{
private:
    Font *font;
    Word *word;
    GEBackground *textBackground;
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
