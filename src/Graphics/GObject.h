/*
 * GObject.h
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#ifndef GOBJECT_H_
#define GOBJECT_H_
#include "GEColor.h"
#include "../GEGraphicsCore.h"
#include <iostream>

class GObject {
private:
	SDL_Rect rect;
	Uint32 color;
	bool visible;
	SDL_Surface * sprite;
	unsigned char collisionmask;
	int xVel;
	int yVel;
    Uint32 colorkey;
public:
	GObject(int x, int y, int w, int h,bool visible);
	GObject(int x, int y, int w, int h,bool visible,unsigned char collisionmask);
	GObject(int x, int y, int w, int h,bool visible,unsigned char r,unsigned char g,unsigned char b);
	virtual ~GObject();

    void setColorKey(Uint32 c)
    {
        colorkey = c;
    }

    Uint32 getColorKey()
    {
        return colorkey;
    }

	int getH() const {
		return rect.h;
	}

	void setH(int h) {
		this->rect.h = h;
	}

	int getW() const {
		return rect.w;
	}

	void setW(int w) {
		this->rect.w = w;
	}

	int getX() const {
		return rect.x;
	}

	void setX(int x) {
		this->rect.x = x;
	}

	int getY() const {
		return rect.y;
	}

	void setY(int y) {
		this->rect.y = y;
	}

	virtual void Draw() = 0;

	Uint32 getColor() const {
		return color;
	}

	void setColor(unsigned char r,unsigned char g,unsigned char b) {
		this->color = SDL_MapRGB(screen->format,r,g,b);
	}

	bool isVisible() const {
		return visible;
	}

	void setVisible(bool visible) {
		this->visible = visible;
	}

	SDL_Rect * getRect() {
		return &rect;
	}

	void setRect(SDL_Rect rect) {
		this->rect = rect;
	}

	unsigned char getCollisionmask() const {
		return collisionmask;
	}

	void setCollisionmask(unsigned char collisionmask) {
		this->collisionmask = collisionmask;
	}

	void transform(int x,int y, int w, int h)
	{
		this->rect.x = x;
		this->rect.y = y;
		this->rect.w = w;
		this->rect.h = h;
	}

	virtual void Update()
	{
		rect.x += xVel;
		rect.y += yVel;
	}

	void Move(int xVel,int yVel)
	{
		this->setX(this->getX() + xVel);
		this->setY(this->getY() + yVel);
	}

	int getXVel() const {
		return xVel;
	}

	void setVel(int xvel,int yvel) {
		xVel = xvel;
		yVel = yvel;
	}

	int getYVel() const {
		return yVel;
	}

	void setSprite(std::string loc)
	{
		sprite = GEGraphicsCore::loadSprite(loc);
	}

	SDL_Surface * getSprite()
	{
		return sprite;
	}
};

#endif /* GOBJECT_H_ */
