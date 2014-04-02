/*
 * graphics.h
 *
 *  Created on: 12/02/2014
 *      Author: jordy
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#include "GEGlobal.h"
#include "SDL/SDL.h"
#include <iostream>
#include "SDL/SDL_image.h"
#include "Graphics/GEColor.h"

extern SDL_Surface * screen;
using namespace std;

class GEGraphicsCore {
public:
	GEGraphicsCore();

    static void DrawRectangle(int x, int y, int w,int h,Uint32 color);
    static void Grid(Uint32 color, int size );
	static void drawSurface_Rect(SDL_Surface* source, SDL_Surface* destination,
			SDL_Rect offset);

	static void drawSurface_Pos(int x, int y, SDL_Surface* source,
			SDL_Surface* destination,SDL_Rect *sourceRect);

	static void clearScreen( char r, char  g, char  b);

	static void clearScreen(Uint32 color);

	static bool initGraphics();

    static void UpdateScreen();

	static SDL_Surface *loadSprite(string location);

	virtual ~GEGraphicsCore();
};

#endif /* GRAPHICS_H_ */

