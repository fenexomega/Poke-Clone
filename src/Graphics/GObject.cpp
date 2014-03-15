/*
 * GObject.cpp
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#include "GObject.h"

GObject::~GObject() {
	// TODO Auto-generated destructor stub
	SDL_FreeSurface(sprite);
}

GObject::GObject(int x, int y, int w, int h,bool visible)
{
	this->color = GEColor::getColor(255,255,255);
	this->rect.x = x;
	this->rect.y = y;
	this->rect.h = h;
	this->rect.w = w;
	this->visible = visible;
	this->collisionmask = 0b0001;
	this->sprite = NULL;
	xVel = yVel = 0;

}

GObject::GObject(int x, int y, int w, int h,bool visible,unsigned char collisionmask)
{
	this->color = GEColor::getColor(255,255,255);
	this->rect.x = x;
	this->rect.y = y;
	this->rect.h = h;
	this->rect.w = w;
	this->visible = visible;
	this->collisionmask = collisionmask;
	this->sprite = NULL;
	xVel = yVel = 0;
}


GObject::GObject(int x, int y, int w, int h,bool visible,unsigned char r,unsigned char g,unsigned char b)
{
	this->color = GEColor::getColor(r,g,b);
	this->rect.x = x;
	this->rect.y = y;
	this->rect.h = h;
	this->rect.w = w;
	this->visible = visible;
	this->collisionmask = 0b0001;
	this->sprite = NULL;
	xVel = yVel = 0;
}
