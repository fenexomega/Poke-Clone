/*
 * GEColor.h
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#ifndef GECOLOR_H_
#define GECOLOR_H_
#include "SDL/SDL.h"

extern SDL_Surface * screen;
class GEColor {
public:
	GEColor();
	virtual ~GEColor();
	static Uint32 getColor( char r, char g, char b)
	{
		return SDL_MapRGB(screen->format,r,g,b);
	}
	static Uint32 Blue()
	{
		return SDL_MapRGB(screen->format,0,0,255);
	}

	static Uint32 Red()
	{
		return SDL_MapRGB(screen->format,255,0,0);
	}
	static Uint32 Green()
	{
		return SDL_MapRGB(screen->format,0,255,0);
	}

};

#endif /* GEColor_H_ */
