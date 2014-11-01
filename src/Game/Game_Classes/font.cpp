#include "font.h"

extern float deltaTime;

Font::Font()
{
    letters = new GESpriteSheet(GE_GLOBAL_FONT_IMAGE,GE_GLOBAL_TILESIZE/2,1);
    showing = false;
}

int Font::GetLetterNumber(char c)
{
    switch(c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    case 'G':
        return 16;
    case 'H':
        return 17;
    case 'I':
        return 18;
    case 'J':
        return 19;
    case 'K':
        return 20;
    case 'L':
        return 21;
    case 'M':
        return 22;
    case 'N':
        return 23;
    case 'O':
        return 24;
    case 'P':
        return 25;
    case 'Q':
        return 26;
    case 'R':
        return 27;
    case 'S':
        return 28;
    case 'T':
        return 29;
    case 'U':
        return 30;
    case 'V':
        return 31;
    case 'W':
        return 32;
    case 'X':
        return 33;
    case 'Y':
        return 34;
    case 'Z':
        return 35;
    case 'a':
        return 36;
    case 'b':
        return 37;
    case 'c':
        return 38;
    case 'd':
        return 39;
    case 'e':
        return 40;
    case 'f':
        return 41;
    case 'g':
        return 42;
    case 'h':
        return 43;
    case 'i':
        return 44;
    case 'j':
        return 45;
    case 'k':
        return 46;
    case 'l':
        return 47;
    case 'm':
        return 48;
    case 'n':
        return 49;
    case 'o':
        return 50;
    case 'p':
        return 51;
    case 'q':
        return 52;
    case 'r':
        return 53;
    case 's':
        return 54;
    case 't':
        return 55;
    case 'u':
        return 56;
    case 'v':
        return 57;
    case 'w':
        return 58;
    case 'x':
        return 59;
    case 'y':
        return 60;
    case 'z':
        return 61;
    case '.':
        return 62;
    case ' ':
        return 63;
    case '[':
        return 64;
    case ']':
        return 65;
    case '_':
        return 66;
    case '?':
        return 67;
    case '!':
        return 68;
    case '\n':
        return 69;
    case '\f':
        return 70;
    case '>':
        return 71;
    case '-':
        return 72;
    default: return 66;
    }

}


void Font::WriteChar(char c,int x, int y)
{
    int n = GetLetterNumber(c);
    GEGraphicsCore::drawSurface_Pos(x,y,letters->getSprite(),screen,letters->getRect(n));
}


void Font::WriteString(string s, int x, int y,int maximumWidth)
{
    int auxX;
    int aux = 0; //GE_GLOBAL_SCREEN_WIDTH/(GE_GLOBAL_TILESIZE/2)
    y *= GE_GLOBAL_TILESIZE/2;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        if(i >= maximumWidth + (maximumWidth * aux) )
        {
            aux++;
            y += GE_GLOBAL_TILESIZE;
        }
        auxX = ((i%maximumWidth + 1) * 32);
        if(auxX == 0 && x > 0)
            auxX = x*32;
        WriteChar(s[i],auxX,y);

    }
}

Font::~Font()
{
	delete letters;
}
