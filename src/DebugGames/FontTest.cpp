#include "FontTest.h"
#include "../GEInput.h"

string frase = "Ola! Lembre-se que voce nao pode usar sinais! Nem virgula! Nem hifem!";

FontTest::FontTest()
{
    font = new Font();
    aux = false;
}

FontTest::~FontTest()
{

}


void FontTest::gameInit()
{

}

void FontTest::gameRun()
{

}

void FontTest::gameUpdate(long currentTime)
{
    if(aux)
        if(GEInput::isKeyDown(SDLK_SPACE))
            aux = false;
}

void FontTest::gameDraw()
{
    if(!aux)
        aux = font->WriteWithTime(frase,0,3,20,3+4);
    else
       font->WriteString(frase,0,3,20,3+4);
}

void FontTest::gameDispose()
{

}
