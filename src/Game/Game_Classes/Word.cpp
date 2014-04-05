#include "Word.h"

extern float deltaTime;
Word::Word(string s, int x, int y, int limit, Font *font)
{
    this->phrase = s;
    this->x = x;
    this->y = y;
    this->limit = limit;
    this->font = font;
    animated = false;
    background = new GEBackground(0,GE_GLOBAL_TILESIZE * 6, "textbackground4x.png");
    this->active = false;
}

Word::Word(int x, int y, int limit)
{
    this->x = x;
    this->y = y;
    this->limit = limit;
    this->font = new Font();
    animated = false;
    this->active = false;
    background = new GEBackground(0,GE_GLOBAL_TILESIZE * 6, "textbackground4x.png");
}

void Word::Begin(string s)
{
    this->phrase = s;
    active = true;
    animated = false;
    Continue();
}

bool Word::isActive()
{
    return active;
}

bool Word::Continue()
{
    if(!animated)
    {
        s = phrase.substr(0,limit*2);
        phrase.erase(0,limit*2);
    }
    i = 0;
    timeAux = 0;
    if(animated)
        animated = false;
    else
        animated = true;
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

    if(animated)
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
                return !(animated = false);
            }
        }
        font->WriteString(s.substr(0,i),x,y,limit);
    }
    return !animated; //Retorna se acabou

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
