/*
 * Square.cpp
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#include "Square.h"

Square::Square(int x,int y,int w, int h) : GObject(x,y,w,h) {
    
}

Square::Square(int x,int y,int w, int h,char r, char g, char b) : GObject(x,y,w,h,r,g,b) {
}

Square::~Square() {
}

void Square::Draw()
{
        if( (getX() + getW() >= 0) && (getY() + getH() >= 0) )
            if( (getX() <= GE_GLOBAL_SCREEN_WIDTH) && (getY() <= GE_GLOBAL_SCREEN_HEIGHT))
                GEGraphicsCore::DrawRectangle(getX(),getY(),getW(),getH(),getColor());
}

