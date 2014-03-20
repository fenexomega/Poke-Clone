#include "Word.h"

extern float deltaTime;
Word::Word(string s, int x, int y, int limit, Font *font)
{
    this->phrase = s;
    this->x = x;
    this->y = y;
    this->limit = limit;
    this->font = font;
    showing = false;
    background = new GEBackground(0,GE_GLOBAL_TILESIZE * 6, "textbackground4x.png");
}

void Word::Begin(string s)
{
    this->phrase = s;
    Continue();
}


bool Word::Continue()
{
    s = phrase.substr(0,limit*2);
    phrase.erase(0,limit*2);
    i = 0;
    timeAux = 0;
    showing = true;
    active = !s.empty();
    return active;
}

void Word::Draw()
{
    if(active)
    {
        background->Draw();
        if(WriteInDelay())
            Write();
    }
}

bool Word::WriteInDelay()
{

    if(showing)
    {
        if((timeAux += deltaTime ) > 50)
        {
            i++;
            timeAux = 0;
            if(i >= limit*2 || i > s.size())
            {
                i = s.size();
                font->WriteString(s.substr(0,i),x,y,limit);
                font->WriteChar('>',32*18,16*32);
                return !(showing = false);
            }
        }
        font->WriteString(s.substr(0,i),x,y,limit);
    }
    return !showing; //Retorna se acabou

}

void Word::Write()
{
    font->WriteString(s,x,y,limit);
    font->WriteChar('>',32*18,16*32);
}

Word::~Word()
{
    delete font;
    delete background;
}
