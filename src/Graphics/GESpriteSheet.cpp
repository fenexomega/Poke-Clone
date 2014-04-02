/*
 * GESpriteSheet.cpp
 *
 *  Created on: 10/03/2014
 *      Author: jordy
 */

#include "GESpriteSheet.h"

GESpriteSheet::GESpriteSheet(string image,  char tileSize,int type) : GObject(0,0,0,0,true)
{
	SDL_Rect *auxRect;
    this->setSprite(image);
	setW(getSprite()->w);
	setH(getSprite()->h);
    if(type == 0) //Se for mapa...
        tiles.push_back(NULL); //adicione um tile null, para que comece do 1.
	for(int i = 0; i*tileSize < getH(); i++)
	{
		for(int x = 0; x < getW(); x += tileSize)
		{
			auxRect = new SDL_Rect;
			auxRect->w = auxRect->h = tileSize;
            auxRect->x = x;
            auxRect->y = i*tileSize;
			tiles.push_back(auxRect);
		}


	}
}

GESpriteSheet::~GESpriteSheet()
{

}

SDL_Rect * GESpriteSheet::getRect(int n)
{
	return tiles[n];
}

void GESpriteSheet::Draw()
{

}

