/*
 * GEBackground.cpp
 *
 *  Created on: 24/02/2014
 *      Author: jordy
 */

#include "GEBackground.h"

//GEBackground::GEBackground() {
//	// TODO Auto-generated constructor stub
//
//}

GEBackground::~GEBackground() {
	// TODO Auto-generated destructor stub

}

GEBackground::GEBackground(int x, int y,std::string spriteloc) : GObject(x,y,0,0,true)
{
	this->setSprite(spriteloc);
	setW(getSprite()->w);
	setH(getSprite()->h);

}


void GEBackground::Draw()
{
	GEGraphicsCore::drawSurface_Rect(getSprite(),screen,*getRect());
}
