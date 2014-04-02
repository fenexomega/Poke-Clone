/*
 * Square.h
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "GObject.h"
#include "../GEGlobal.h"

class Square: public GObject {
public:
	Square(int x,int y,int w, int h, bool visible);
	Square(int x,int y,int w, int h, bool visible,  char r, char g, char b);
	virtual ~Square();

	void Draw()
	{
		if(isVisible())
			if( (getX() + getW() >= 0) && (getY() + getH() >= 0) )
				if( (getX() <= GE_GLOBAL_SCREEN_WIDTH) && (getY() <= GE_GLOBAL_SCREEN_HEIGHT))
					SDL_FillRect(screen,getRect(),getColor());
	}

};

#endif /* SQUARE_H_ */
