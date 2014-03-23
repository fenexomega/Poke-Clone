#include "FontTest.h"
#include "../GEInput.h"

string frase = "Ola! Lembre-se   que voce nao pode usar sinais! Nem virgula! E nem  mesmo tio! kakakakakakakakakaka";

FontTest::FontTest()
{
    font = new Font();
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
    if(GEInput::isKeyDown(GEInput::a))
    {
        if(word->isActive())
            word->Continue();
        else
            word->Begin(frase);
    }

}

void FontTest::gameDraw()
{
    word->Draw();
}

void FontTest::gameDispose()
{

}
