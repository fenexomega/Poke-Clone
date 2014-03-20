#include "FontTest.h"
#include "../GEInput.h"

string frase = "Ola! Lembre-se   que voce nao pode usar sinais! Nem virgula! Nem   hifem! kkkkkkkk";
//string frase = "1-_-2-_-3-_-4-_-5-_-6-_-7-_-8-_-9-_-10-_-11-_-12->-13-_-14->-15-_-16->-17";

FontTest::FontTest()
{
    font = new Font();
    aux = false;
    word = new Word(frase,1,14,17,font);
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
        if(GEInput::isKeyDown(SDLK_SPACE))
        {
            word->Begin(frase);
        }
        if(GEInput::isKeyDown(SDLK_a))
        {
            aux = false;
            word->Continue();
        }

}

void FontTest::gameDraw()
{
    word->Draw();
}

void FontTest::gameDispose()
{

}
