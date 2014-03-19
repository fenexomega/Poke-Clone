#include "Word.h"

extern float deltaTime;
Word::Word(string s, int x, int y, int limit, Font *font)
{
    this->s = s;
    this->x = x;
    this->y = y;
    this->limit = limit;
    this->font = font;
    showing = false;
}

void Word::setString(string s)
{
    this->s = s;
}


bool Word::WriteInDelay()
{
    if(!showing)
    {
        i = 0;
        showing = true;
        timeAux = 0;
    }
    else
    {
        if((timeAux += deltaTime ) > 50)
        {
            i++;
            timeAux = 0;
            if(i >= limit*2)
            {
                s.erase(0,limit);
                i = limit - 1;
            }
            if(i >= s.size())
            {
                showing = false;
                font->WriteChar('>',32*18,16*32);
            }
        }
    }
    font->WriteString(s.substr(0,i),x,y,limit);
    return !showing; //Retorna se acabou

}

void Word::Write()
{
    font->WriteString(s,x,y,limit);
    font->WriteChar('>',32*18,16*32);

}
