/*
 * GEPhysics.cpp
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#include "GEPhysics.h"

GEPhysics::GEPhysics() {
	// TODO Auto-generated constructor stub

}

bool GEPhysics::isColliding(GObject * obj1,GObject * obj2)
{
	if(obj1 == obj2)
		return false;
	if(obj1->getX() + obj1->getW() >= obj2->getX() &&
	   obj1->getX()  <= obj2->getX() + obj2->getW())
		if(obj1->getY() + obj1->getH() >= obj2->getY() &&
	       obj1->getY() + obj1->getH() <= obj2->getY() + obj2->getH())
				if(obj1->getCollisionmask() == obj2->getCollisionmask())
					return true;
	return false;
}

int GEPhysics::isOnBorders(GObject *obj)
{
	if(obj->getX() + obj->getW() >= GE_GLOBAL_SCREEN_WIDTH || obj->getX() <= 0)
		return X_AXIS_COL;
	if(obj->getY() + obj->getH() >= GE_GLOBAL_SCREEN_HEIGHT || obj->getY() <= 0)
		return Y_AXIS_COL;
	return NO_COL;
}

GEPhysics::~GEPhysics() {
	// TODO Auto-generated destructor stub
}

